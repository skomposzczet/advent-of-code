INPUT_FILENAME = 'input.txt'

SHAPE_PTS = {
    'X': 1,
    'Y': 2,
    'Z': 3,
}

WIN_MAP = {
    'A': 'Y',
    'B': 'Z',
    'C': 'X',
}

DRAW_MAP = {
    'A': 'X',
    'B': 'Y',
    'C': 'Z',
}

LOSE_MAP = {
    'A': 'Z',
    'B': 'X',
    'C': 'Y',
}

MAP_MAP = {
    'X': LOSE_MAP,
    'Y': DRAW_MAP,
    'Z': WIN_MAP,
}

def get_outcome_score(opponent, me):
    if WIN_MAP[opponent] == me:
        return 6
    elif DRAW_MAP[opponent] == me:
        return 3
    return 0

def part1():
    score = 0
    with open(INPUT_FILENAME) as input_file:
        for line in input_file:
            opponent, me = line[:3].split(' ')
            score += SHAPE_PTS[me]
            score += get_outcome_score(opponent, me)
            
    print(score)

def part2():
    score = 0
    with open(INPUT_FILENAME) as input_file:
        for line in input_file:
            opponent, outcome = line[:3].split(' ')
            me = MAP_MAP[outcome][opponent]
            score += SHAPE_PTS[me]
            score += get_outcome_score(opponent, me)

    print(score)

if __name__ == '__main__':
    part1()
    part2()