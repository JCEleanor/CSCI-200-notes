# Sorting

## Min/Max

## Sorting

### 1. Selection Sort

In two loops, koep finding the min/max value and swaping the min/max to the first place (index = 0)

#### Pseudo Code

```
for i=0 to end
  k = i
  for j=i+1 to end
    if list[j] < list[k]
      k = j
  swap list[i] & list[k]

```

#### Time Complexity

- worse/best/average case: O(n^2)

### 2. Insertion Sort

#### Pseudo Code

```
for i=1 to n // start with the second element
  x = list[i]
  j = i-1
  while j >= 0 and list[j] > x
    list[j+1] = list[j]
    j--
  list[j+1] = x

```

#### Time Complexity

- worse/average case: O(n^2)

- best case: o(n)

### 3. Bubble Sort

#### Pseudo Code

```
for i=0 to n
  for j=1 to n-i
    if list[j-1] > list[j]
      swap list[j-1] & list[j]

```

#### Time Complexity

- worse/average case: O(n^2)

- best case: o(n)

### 4. Merge Sort
