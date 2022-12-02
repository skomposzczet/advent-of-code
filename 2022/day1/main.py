INPUT_FILENAME = 'input.txt'

def part1():
    max = 0
    current_sum = 0
    with open(INPUT_FILENAME, 'r') as input_file:
        for line in input_file:
            if line != '\n':
                current_sum += int(line[:-1])
            else:
                max = max if max > current_sum else current_sum
                current_sum = 0
            
    print(max)

def part2():
    top_three = [0] * 3
    current_sum = 0
    with open(INPUT_FILENAME, 'r') as input_file:
        for line in input_file:
            if line != '\n':
                current_sum += int(line[:-1])
            else:
                top_three.append(current_sum)
                top_three.remove(min(top_three))
                current_sum = 0
    
    print(sum(top_three))

if __name__ == '__main__':
    part1()
    part2()