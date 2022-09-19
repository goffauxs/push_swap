# push_swap
42 Sorting Project

## About
The project consists of developing an algorithm to sort a list of numbers using only two stacks and the following operations:

- `sa` : swap a - swap the first 2 elements at the top of stack a.
- `sb` : swap b - swap the first 2 elements at the top of stack b.
- `ss` : `sa` and `sb` at the same time.
- `pa` : push a - move the element at the top of stack b to the top of stack a.
- `pb` : push b - move the element at the top of stack a to the top of stack b.
- `ra` : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
- `rb` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- `rr` : `ra` and `rb` at the same time.
- `rra` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr` : `rra` and `rrb` at the same time.

The algorithm I used is a [Radix Sort](https://en.wikipedia.org/wiki/Radix_sort) as it fits our criteria quite well if we use the numbers in their binary format.

Since the numbers given as parameters cannot contain duplicates, we first sort the list in the background using [Quicksort](https://en.wikipedia.org/wiki/Quicksort) and convert every number to its index in the new sorted list. This has the advantage of giving us the least possible number of digits in our biggest input number.

The algorithm then works in the following way:
```C
/*
	t_stack are structures that contain:
		head: a pointer to the head of a circular linked list
		len: the length of this linked list
	max_digits is the number of digits of the biggest number (in binary) in our list
*/
void	radix_sort(t_stack *a, t_stack *b, size_t max_digits)
{
	size_t	current_digit; // The current digit we are sorting by
	size_t	i; // used to iterate through all members of stack A
	size_t	length = a->len; // the length of stack A

	while (current_digit < max_digits)
	{
		i = 0;
		// iterate over every element of stack A
		while (i < length)
		{
			/* 
				check if the digit we are currently looking at is 1
				if it is, we rotate stack a to move onto the next value
				if it is not, we push it to stack B
			*/
			if ((a->head->val >> current_digit) & 1)
				ft_ra(f);
			else
				ft_pb(f);
			i++;
		}
		/*
			once all numbers with the current digit being 0 are in stack B, 
			we push them back to stack A for the next pass over the next digit
		*/
		while (f->b->len != 0)
			ft_pa(f);
		current_digit++;
	}
}
```

As the algorithm works on the numbers in binary format, the worst case performance complexity would be of <code>O(n * log<sub>2</sub>n)</code>

## Example

Here is a visual example of the algorithm sorting a list of 1 to 50 in random order:

![](https://github.com/goffauxs/push_swap/blob/main/push_swap.gif)
