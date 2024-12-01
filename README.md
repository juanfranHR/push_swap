# Push Swap

Push Swap is a program that employs the radix sort algorithm to sort a list of numbers using a set of allowed movements.

## Allowed Movements

1. **sa (swap a)**: Swap the first two elements at the top of stack `a`.
2. **sb (swap b)**: Swap the first two elements at the top of stack `b`.
3. **ss**: `sa` and `sb` at the same time.
4. **pa (push a)**: Take the first element at the top of stack `b` and put it at the top of stack `a`.
5. **pb (push b)**: Take the first element at the top of stack `a` and put it at the top of stack `b`.
6. **ra (rotate a)**: Shift all elements of stack `a` up by one. The first element becomes the last one.
7. **rb (rotate b)**: Shift all elements of stack `b` up by one. The first element becomes the last one.
8. **rr**: `ra` and `rb` at the same time.
9. **rra (reverse rotate a)**: Shift all elements of stack `a` down by one. The last element becomes the first one.
10. **rrb (reverse rotate b)**: Shift all elements of stack `b` down by one. The last element becomes the first one.
11. **rrr**: `rra` and `rrb` at the same time.

## Usage

To use the Push Swap program, compile the source code and run the executable with a list of numbers as arguments. The program will output the sequence of movements required to sort the list.

```sh
gcc -o push_swap push_swap.c
./push_swap 4 3 2 1
```
## Checker Program

The bonus folder contains a `checker` program that verifies the correctness of the sorting algorithm. To compile and use the `checker`, follow these steps:

1. Compile the `checker` program using `make`:
    ```sh
    make bonus
    ```

2. Run the `checker` program with the same list of numbers and the output of the `push_swap` program:
    ```sh
    ./push_swap 4 3 2 1 | ./checker 4 3 2 1
    ```

The `checker` program will read the sequence of movements from the `push_swap` program and determine if the list is sorted correctly. It will output "OK" if the list is sorted, or "KO" if it is not.

## License
This project is licensed under the MIT License.