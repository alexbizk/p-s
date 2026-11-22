*This project has been created as part of the 42 curriculum by weitwang & furbozor.*

# push_swap

## Description

`push_swap` sorts integers using two stacks and a fixed set of 11 operations. The numbers start on **stack `a`**; **stack `b`** starts empty. The program does not print the sorted numbers: it prints the **list of operations** that sorts `a` in ascending order (smallest on top) with `b` empty, using as few operations as possible.

| Operation | Effect |
|---|---|
| `sa` / `sb` / `ss` | swap the first two elements of `a` / `b` / both |
| `pa` / `pb` | take the top of `b` and put it on `a` / the other way round |
| `ra` / `rb` / `rr` | rotate up: the first element becomes the last (`a` / `b` / both) |
| `rra` / `rrb` / `rrr` | rotate down: the last element becomes the first (`a` / `b` / both) |

This version of the subject asks for:

- **four strategies** in one binary: simple, medium, complex and adaptive;
- a **disorder** metric, measured before any move;
- a `--bench` mode that reports statistics after sorting.

## Instructions

### Compile

```sh
make        # builds libft and push_swap
make clean  # removes object files
make fclean # removes object files and the binary
make re     # fclean + all
```

### Run

```sh
./push_swap [options] numbers...
```

| Option | Effect |
|---|---|
| (none) | same as `--adaptive` |
| `--simple` | force the O(n²) algorithm |
| `--medium` | force the O(n√n) algorithm |
| `--complex` | force the O(n log n) algorithm |
| `--adaptive` | choose by disorder (default) |
| `--bench` | after sorting, print statistics to stderr |

Numbers can be separate arguments (`3 2 1`) or one string (`"3 2 1"`). Options can be placed anywhere among the numbers.

### Output

Operations are printed on **stdout**, one per line. The `--bench` report is printed on **stderr** after sorting, so it never mixes with the operations and the checker only reads the operations.

Example report for 100 random numbers:

```
[bench] disorder:  47.78%
[bench] strategy:  Adaptive / O(n*sqrt(n))
[bench] total_ops:  790
[bench] sa:  0  sb:  0  ss:  0  pa:  100  pb:  100
[bench] ra:  400  rb:  93  rr:  0  rra:  0  rrb:  97  rrr:  0
```

### Errors

`Error` followed by `\n` is written to stderr when an argument:

- is not an integer (`abc`, `1a`, `""`, `-`);
- is outside the `int` range (`2147483648`);
- is a duplicate (`1 2 2`);
- is an unknown option (`--foo`).

With no arguments the program prints nothing.

## Evaluation commands aka the test checklist


Run `bash` first: the subject's examples are written for bash, and zsh does not split `$ARG` on spaces. 
Then choose the checker once; every command below uses `$CHECKER`:

```sh
bash
CHECKER=./checker_Mac        # macOS
CHECKER=./checker_linux      # Linux (run only the line for your machine)
chmod +x $CHECKER
```

### Build

```sh
make
make            # second time: "Nothing to be done" (no relink)
norminette
```

### Basic sorting

```sh
./push_swap 2 1 3 6 5 8                     # 16 operations
./push_swap 3 2 1                           # ra sa
./push_swap 1 2 3                           # nothing (already sorted)
./push_swap                                 # nothing (no arguments)
./push_swap "3 2 1"                         # numbers in one string
```

### Each strategy, checked by the checker

```sh
ARG="4 67 3 87 23"
./push_swap $ARG | $CHECKER $ARG                 # OK
./push_swap --simple $ARG | $CHECKER $ARG        # OK
./push_swap --medium $ARG | $CHECKER $ARG        # OK
./push_swap --complex $ARG | $CHECKER $ARG       # OK
./push_swap --adaptive $ARG | $CHECKER $ARG      # OK
./push_swap --adaptive $ARG | wc -l                     # 9
./push_swap --simple 5 4 3 2 1                          # 14 operations
```

### Performance (100 and 500 random numbers)

```sh
ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l                                # < 1500 (good)
./push_swap $ARG | $CHECKER $ARG                 # OK

ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
./push_swap $ARG | wc -l                                # < 12000 (pass)
./push_swap $ARG | $CHECKER $ARG                 # OK
```

On macOS without `shuf`: `ARG=$(seq 1 500 | sort -R | tr '\n' ' ')`.

### Benchmark mode

```sh
ARG="4 67 3 87 23"
./push_swap --bench --adaptive $ARG 2> bench.txt | $CHECKER $ARG ; cat bench.txt
./push_swap --bench $ARG > /dev/null                    # only the report
# Without --bench, nothing must go to stderr:
#   2>&1        send stderr into the pipe
#   >/dev/null  throw stdout (the operations) away
#   wc -c       count the characters left: 0 = no report
./push_swap $ARG 2>&1 >/dev/null | wc -c                # 0
```

### Errors (each prints `Error` on stderr)

```sh
./push_swap --adaptive 0 one 2 3
./push_swap --simple 3 2 3
./push_swap 1 1
./push_swap 2147483648
./push_swap -2147483649
./push_swap 1 + 2
./push_swap ""
./push_swap --foo 1 2
./push_swap 1 1 2> /dev/null                            # prints nothing: Error goes to stderr
```

### Memory leaks

```sh
leaks --atExit -- ./push_swap 5 4 3 2 1                 # macOS
valgrind --leak-check=full ./push_swap 5 4 3 2 1        # Linux
valgrind --leak-check=full ./push_swap 1 1              # also on error
```

## Algorithms

All strategies share the same basic move: **take numbers out of `a` into `b` in a smart order, then bring them back so that `a` ends up sorted**. The algorithms differ in *which* number they take next, and that choice decides how many rotations they need.

### Step 0: replace values by their rank (index)

Before sorting, every number gets an **index**: its rank among all the numbers (0 = smallest, n-1 = largest).

| value | 42 | -7 | 1000 | 3 |
|---|---|---|---|---|
| **index** | 2 | 0 | 3 | 1 |

After this step, n numbers are always exactly `0 … n-1`, whatever the user typed (negative, huge, far apart). Every algorithm below works on indexes only. This makes "the smallest 23 numbers" simply "indexes 0 to 22", and it lets radix sort use only 9 bits for 500 numbers.

### Disorder: how shuffled is the input?

Look at every pair of numbers (one on the left, one on the right). If the left one is bigger, the pair is a **mistake**. The disorder is:

```
disorder = mistakes / total pairs        (total pairs = n(n-1)/2)
```

| Stack (top first) | Pairs | Mistakes | Disorder |
|---|---|---|---|
| `1 2 3` | 3 | 0 | 0.00 (sorted) |
| `2 1 3` | 3 | 1 (2 before 1) | 0.33 |
| `3 2 1` | 3 | 3 | 1.00 (reversed) |
| `4 67 3 87 23` | 10 | 4 | 0.40 |

It is computed **before any operation** with two nested loops (O(n²) comparisons, no operations printed). Only the adaptive strategy uses it to decide; `--bench` prints it.

### Small inputs: 2 to 5 numbers

**Three numbers** need at most 2 moves. Two rules are enough:

1. Send the **largest** to the bottom: on top → `ra`, in the middle → `rra`, already at the bottom → nothing.
2. If the top two are in the wrong order → `sa`.

| Start | Moves |
|---|---|
| `1 2 3` | none |
| `2 1 3` | `sa` |
| `3 1 2` | `ra` |
| `2 3 1` | `rra` |
| `3 2 1` | `ra sa` |
| `1 3 2` | `rra sa` |

**Four or five numbers** are reduced to three: push the smallest one (or two) to `b`, sort the three left in `a`, then `pa` them back. Example `5 1 4 2 3` (8 moves):

| Move | a (top → bottom) | b | Why |
|---|---|---|---|
| | `5 1 4 2 3` | | |
| `ra` | `1 4 2 3 5` | | smallest (1) is now on top |
| `pb` | `4 2 3 5` | `1` | park it in b |
| `ra` | `2 3 5 4` | `1` | next smallest (2) on top |
| `pb` | `3 5 4` | `2 1` | park it |
| `rra` | `4 3 5` | `2 1` | three left: largest (5) to the bottom |
| `sa` | `3 4 5` | `2 1` | top two were reversed |
| `pa` | `2 3 4 5` | `1` | bring back 2 |
| `pa` | `1 2 3 4 5` | | bring back 1: sorted |

All 120 orders of 5 numbers were tested: at most 10 moves. These small sorts are used by the adaptive strategy; a forced strategy (`--simple`, …) always uses its own algorithm.

### 1. Simple: selection sort, O(n²)

**Idea.** Like picking the shortest person out of a line, again and again: find the smallest number, bring it to the top, put it aside in `b`. When `a` is empty, `b` holds everything with the largest on top, so pushing it all back rebuilds `a` in order.

1. Find the smallest element of `a`.
2. Bring it to the top with `ra` (if it is in the top half) or `rra` (bottom half): the shorter way.
3. `pb` it. Repeat until `a` is empty.
4. `pa` everything back.

Example `./push_swap --simple 2 4 1 3` (12 moves):

| Moves | a (top → bottom) | b |
|---|---|---|
| | `2 4 1 3` | |
| `ra ra` | `1 3 2 4` | |
| `pb` | `3 2 4` | `1` |
| `ra pb` | `4 3` | `2 1` |
| `ra pb` | `4` | `3 2 1` |
| `pb` | | `4 3 2 1` |
| `pa pa pa pa` | `1 2 3 4` | |

**Cost.** For each of the n numbers, reaching the minimum can take up to n/2 rotations: about n × n/2 moves, so O(n²). Measured: about 1500 moves for 100 random numbers, about 32 000 for 500 (5 times more numbers, about 20 times more moves).

**When it is the best.** When the input is almost sorted, the minimum is usually already near the top, so each step costs almost nothing.

### 2. Medium: chunk sort, O(n√n)

**Idea.** Searching `a` for one exact number is slow. Searching for *any* number of a group is fast, because one of them is usually close. So we split the indexes into groups (chunks) of size k ≈ √n, move the groups to `b` one by one, then bring the numbers back largest first.

Chunk size = the smallest k with k × k ≥ n: 10 for 100 numbers, 23 for 500.

**Phase 1: push the chunks to `b`, smallest chunk first.** Look at the top of `a`: if it belongs to the current chunk, `pb`; otherwise `ra` and look at the next one. When the chunk is complete, move on to the next chunk.

**Phase 2: bring back the largest each time.** Find the largest index in `b`, bring it to the top with `rb` or `rrb` (the shorter way), `pa`. Repeat until `b` is empty.

Example `./push_swap --medium 8 3 6 0 7 1 5 2 4` (9 numbers, so k = 3, chunks `0–2`, `3–5`, `6–8`; 32 moves):

| After | a (top → bottom) | b (top → bottom) |
|---|---|---|
| start | `8 3 6 0 7 1 5 2 4` | |
| chunk `0–2` pushed | `4 8 3 6 7 5` | `2 1 0` |
| chunk `3–5` pushed | `8 6 7` | `5 3 4 2 1 0` |
| chunk `6–8` pushed | | `7 6 8 5 3 4 2 1 0` |
| phase 2 done | `0 1 2 3 4 5 6 7 8` | |

After phase 1, `b` is not sorted, but it is **sorted by groups**: the largest group sits on top. So in phase 2 the current maximum is always within the top few positions, never deep down.

**Cost.** Phase 1: one chunk needs at most one full turn of `a` (≤ n moves), and there are √n chunks → at most n√n. Phase 2: each of the n numbers needs at most about √n rotations → n√n. Total O(n√n). Measured: about 800 moves for 100 random numbers (our best strategy for 100), about 8100 for 500.

### 3. Complex: LSD radix sort, O(n log n)

**Idea.** Write every index in binary and sort by **one bit at a time**, starting with the lowest bit. For each bit, numbers whose bit is 0 go to `b` (`pb`), numbers whose bit is 1 stay in `a` (`ra`), then `b` comes back on top (`pa`). After the last bit, `a` is sorted.

For one pass:

1. Look at each element of `a` exactly once: bit = 0 → `pb`, bit = 1 → `ra`.
2. `pa` everything from `b`.

Example `./push_swap --complex 5 2 9 1` (12 moves). The indexes are 5→2, 2→1, 9→3, 1→0, so `a` = `2 1 3 0`:

| Index | 2 | 1 | 3 | 0 |
|---|---|---|---|---|
| Binary | `10` | `01` | `11` | `00` |

The largest index is 3, which needs 2 bits, so there are 2 passes:

| Pass | Bit of each element (in order) | Moves | a after the pass |
|---|---|---|---|
| bit 0 | 2→0, 1→1, 3→1, 0→0 | `pb ra ra pb pa pa` | `2 0 1 3` (bit 0 now reads 0 0 1 1) |
| bit 1 | 2→1, 0→0, 1→0, 3→1 | `ra pb pb ra pa pa` | `0 1 2 3` sorted |

**Why it works.** In each pass, numbers with the same bit keep their relative order (`pb` reverses them, `pa` reverses them back). So after sorting by bit 0, then by bit 1, and so on, the order by all bits together is correct.

**Cost.** Each pass costs at most 2n moves, and there are ⌈log₂ n⌉ passes (7 for 100 numbers, 9 for 500) → O(n log n). Unlike the other two, its cost **does not depend on the order** of the input: 1084 moves for any 100 numbers, 6784 for any 500. That is why it wins on very shuffled input and wastes moves on almost-sorted input.

[Interactive Radix Sort Visualizer](https://alexbizk.github.io/p-s/)

### 4. Adaptive

**Idea.** Look before you sort. The adaptive strategy does not sort by itself; it measures the input and hands it to the algorithm that should be cheapest:

1. 5 numbers or fewer → small sort.
2. Otherwise compute the disorder, then:

| Disorder | Algorithm | Reason |
|---|---|---|
| < 0.2 | simple | most numbers are near their place, so the minimum is always close to the top |
| 0.2 – 0.5 | medium | balanced cost for partly shuffled input |
| ≥ 0.5 | complex | radix costs the same whatever the order, so it wins when the input is very messy |

The thresholds live in a single function, `adaptive_choice`, which `--bench` also calls, so they exist in one place only.

Measured results (number of moves, same input for every strategy, best in bold):

| n | Disorder | simple | medium | complex | adaptive |
|---|---|---|---|---|---|
| 100 | 5.8% | **264** | 400 | 1084 | 264 |
| 100 | 22.1% | 816 | **679** | 1084 | 679 |
| 100 | 42.0% | 1536 | **771** | 1084 | 771 |
| 500 | 0.8% | **1491** | 1776 | 6784 | 1491 |
| 500 | 5.0% | **4038** | 4648 | 6784 | 4038 |
| 500 | 13.1% | 10038 | **6246** | 6784 | 10038 |

The adaptive strategy picks the best algorithm in most cases. The last row shows the limit of the default thresholds: with 500 numbers, simple sort becomes expensive already at about 13% disorder.

### Complexity summary

| Strategy | Moves | Extra memory |
|---|---|---|
| simple | O(n²) | O(1) |
| medium | O(n√n) | O(1) |
| complex | O(n log n) | O(1) |
| adaptive | bound of the selected algorithm, plus O(n²) comparisons for the disorder | O(1) |

Extra memory does not count the two stacks themselves (O(n) nodes in total).

### Counting operations without global variables

The subject forbids global variables. The operation counter is a `static int count[11]` declared **inside** the function `op_counter()`, which returns a pointer to it. Every operation calls `put_op(name, id)`, which prints the operation and increments `count[id]`. The total is the sum of the 11 counters.

## Project structure

```
push_swap.c      main(): parse options, parse numbers, sort, free
parsing/         number validation, duplicates, option parsing
stack/           linked list helpers, index assignment, min/max search
operations/      the 11 operations and the operation counter
sorting/         small sorts, simple, medium, radix, adaptive, disorder, dispatcher
bench/           --bench report
Libft/           our libft
```

## Contributions

- **weitwang**: ...
- **furbozor**: ...

## Resources

- The push_swap subject (42)
- Wikipedia: [Selection sort](https://en.wikipedia.org/wiki/Selection_sort), [Radix sort](https://en.wikipedia.org/wiki/Radix_sort), [Bucket sort](https://en.wikipedia.org/wiki/Bucket_sort), [Inversion (discrete mathematics)](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics))

### Use of AI

We used AI as a tutor during the project:

- to explain the subject, the stack operations, Big-O notation, the disorder metric and the algorithms in plain language;
- to review our code and find bugs (for example the `long` overflow in number validation, missing files in the Makefile, and Norm issues);
- to suggest the design of some parts (the static operation counter, option parsing, the `--bench` output, `adaptive_choice`) and to write a first draft of this README.

Every line of code was typed, tested and understood by us, and both of us can explain any part of it.
