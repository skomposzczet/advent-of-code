INPUT_FILENAME = 'input.txt'

MARKER_LEN_PART1 = 4
MARKER_LEN_PART2 = 14

def areAllDifferent(s):
    char_set = set()
    for letter in s:
        if letter not in char_set:
            char_set.add(letter)
        else:
            return False
    return True

def part_gen(marker_len):
    with open(INPUT_FILENAME) as input_file:
        line = input_file.readline()

    result = 0
    for i in range(0, len(line)-marker_len):
        if areAllDifferent(line[i:i+marker_len]):
            result = i+marker_len
            break

    print(result)

if __name__ == '__main__':
    part_gen(MARKER_LEN_PART1)
    part_gen(MARKER_LEN_PART2)