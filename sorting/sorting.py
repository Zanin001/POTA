import time

def read_file(path):
    with open(path, 'r') as file:
        numbers = file.read().strip().split()
        return [int(number) for number in numbers]


def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

def main():
    numbers = read_file('numbers.txt')
    print("Números originais:", numbers)
    
    bubble_numbers = numbers.copy()
    bubble_init = time.time()
    bubble_sort(bubble_numbers)
    bubble_end = time.time()
    bubble_time = bubble_end - bubble_init
    
    insert_numbers = numbers.copy()
    insert_init = time.time()
    insertion_sort(insert_numbers)
    insertion_end = time.time()
    insertion_time = insertion_end - insert_init
    
    print("-------------------------------------------------------------------------------------------------")
    print("Números ordenados com Bubble Sort:", bubble_numbers)
    print("-------------------------------------------------------------------------------------------------")
    print("Números ordenados com Insertion Sort:", insert_numbers)
    print("-------------------------------------------------------------------------------------------------")

    print("Tempo para Bubble Sort:", bubble_time, "segundos")
    print("Tempo para Insertion Sort:", insertion_time, "segundos")

if __name__ == "__main__":
    main()
