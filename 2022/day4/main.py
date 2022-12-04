INPUT_FILENAME = 'input.txt'

BEGIN, END = 0, 1

def containsOther(pair):
    ranges = [list(map(int, assingment.split('-'))) for assingment in pair]
    if ranges[0][BEGIN] <= ranges[1][BEGIN] and ranges[0][END] >= ranges[END][1]:
        return True
    if ranges[1][BEGIN] <= ranges[0][BEGIN] and ranges[1][END] >= ranges[0][END]:
        return True
    return False

def containsAtLeastBarelyOther(pair):
    ranges = [list(map(int, assingment.split('-'))) for assingment in pair]
    if ranges[0][BEGIN] <= ranges[1][END] <= ranges[0][END]:
        return True
    if ranges[0][BEGIN] <= ranges[1][BEGIN] <= ranges[0][END]:
        return True
    return containsOther(pair)

def part1():
    counter = 0
    with open(INPUT_FILENAME) as input_file:
        for line in input_file:
            if containsOther(line.split(',')):
                counter += 1

    print(counter)

def part2():
    counter = 0
    with open(INPUT_FILENAME) as input_file:
        for line in input_file:
            line = line.strip('\n')
            if containsAtLeastBarelyOther(line.split(',')):
                counter += 1

    print(counter)

if __name__ == '__main__':
    part1()
    part2()