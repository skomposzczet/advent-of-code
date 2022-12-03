from functools import reduce

INPUT_FILENAME = 'input.txt'

def get_priority(item):
    item = ord(item)
    if item >= ord('a') and item <= ord('z'):
        return item - ord('a') + 1
    elif item >= ord('A') and item <= ord('Z'):
        return item - ord('A') + 27
    else:
        raise ValueError(item)

def find_common_items_rucksack(first, second):
    return [item for item in first if item in second]

def find_common_items_group(group):
    return list(reduce(find_common_items_rucksack, group))

def part1():
    sum = 0
    with open(INPUT_FILENAME) as input_file:
        for line in input_file:
            sum += get_priority(find_common_items_rucksack(line[:len(line)//2], line[len(line)//2:])[0])

    print(sum)

def part2():
    group = []
    sum = 0
    with open(INPUT_FILENAME) as input_file:
        for line in input_file:
            group.append(line)
            if len(group) == 3:
                sum += get_priority(find_common_items_group(group)[0])
                group = []
    
    print(sum)

if __name__ == '__main__':
    part1()
    part2()