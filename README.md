# sort

**Gprof**  results for 10,000-strings:

**Bubble sort**
 
| % time | cumulative seconds | self seconds |     call   | self s/call | total s/call |     name   |
|:------:|:------------------:|:------------:|:----------:|:-----------:|:------------:|:----------:|
|  80.87 |              10.82 |        10.82 |    99980001|        0.00 |         0.00 | comparator |
|  18.31 |              13.27 |         2.45 |           1|        2.45 |        13.27 | bubblesort |
|   0.82 |              13.38 |         0.11 |            |             |              | main       |

**Insertion sort**

| % time | cumulative seconds | self seconds |     call   | self s/call | total s/call |     name   |
|:------:|:------------------:|:------------:|:----------:|:-----------:|:------------:|:----------:|
|  52.55 |             1.03   |       1.03   | 22925832   |        0.00 |         0.00 | comparator |
|  41.33 |             1.84   |        0.81  |          1 |       0.81  |       184    | Insertion  |
|   6.12 |             1.96   |         0.12 |            |             |              | main       |

**Quick sort**

| % time | cumulative seconds | self seconds |     call   | self s/call | total s/call |     name   |
|:------:|:------------------:|:------------:|:----------:|:-----------:|:------------:|:----------:|
|  33.33 |               0.05 |         0.02 |      136836|        0.00 |         0.00 | comparator |
|  16.67 |               0.06 |         0.01 |           1|       10.00 |        30.00 | quicksort |
|  50.00 |               0.03 |         0.03 |            |             |              | main       |


**Merge sort**

| % time | cumulative seconds | self seconds |     call   | self s/call | total s/call |     name   |
|:------:|:------------------:|:------------:|:----------:|:-----------:|:------------:|:----------:|
|  44.44 |               0.09 |         0.04 |       9999 |        0.00 |          0.00| merge      |
|   0.00 |               0.09 |         0.00 |          1 |        0.00 |         40.00| mergesort  |
|   0.00 |               0.09 |         0.00 |     117271 |        0.00 |          0.00| comparator |
|  55.56 |               0.05 |         0.05 |            |             |              | main       |
