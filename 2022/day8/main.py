from functools import reduce

INPUT_FILENAME = 'input.txt'

class Forest:
    def __init__(self, grid):
        self.grid = grid
        self.height = len(self.grid)
        self.width = len(self.grid[0])

    def count_visible_trees(self):
        result = 2*self.width + 2*self.height - 4

        for i in range(1, self.height-1):
            for j in range(1, self.width-1):
                result += self.check_tree_visibility(i, j)

        return result

    def check_tree_visibility(self, i, j):
        for side in ['top', 'bot', 'right', 'left']:
            if self.visible_from_side(side, i, j):
                return 1
        return 0

    def visible_from_side(self, side, i, j):
        if side in ['top', 'bot']:
            return self.check_visible_vertical(side, i, j)
        if side in ['right', 'left']:
            return self.check_visible_horizontal(side, i, j)
        else:
            raise f'No such side exists: {side}'

    def check_visible_vertical(self, side, i, j):
        value = self.grid[i][j]
        if side == 'top':
            delta, limit = -1, -1
        elif side == 'bot':
            delta, limit = 1, self.height

        for tree_index in range(i+delta, limit, delta):
            if self.grid[tree_index][j] >= value:
                return False
        return True
    
    def check_visible_horizontal(self, side, i, j):
        value = self.grid[i][j]
        if side == 'left':
            delta, limit = -1, -1
        elif side == 'right':
            delta, limit = 1, self.width

        for tree_index in range(j+delta, limit, delta):
            if self.grid[i][tree_index] >= value:
                return False
        return True

    def get_highest_scenic_score(self):
        current_max = 0

        for i in range(1, self.height-1):
            for j in range(1, self.width-1):
                score = self.get_scenic_score(i, j)
                if score > current_max:
                    current_max = score
        
        return current_max

    def get_scenic_score(self, i, j):
        score = []
        for side in ['top', 'bot', 'right', 'left']:
            score.append(self.scenic_score_from_side(side, i, j))
        # print('debug:', i, j, score)
        return reduce(lambda x,y: x*y, score)

    def scenic_score_from_side(self, side, i, j):
        if side in ['top', 'bot']:
            return self.scenic_score_vertical(side, i, j)
        if side in ['right', 'left']:
            return self.scenic_score_horizontal(side, i, j)
        else:
            raise f'No such side exists: {side}'

    def scenic_score_vertical(self, side, i, j):
        value = self.grid[i][j]
        result = 0
        if side == 'top':
            delta, limit = -1, -1
        elif side == 'bot':
            delta, limit = 1, self.height

        for tree_index in range(i+delta, limit, delta):
            result += 1
            if self.grid[tree_index][j] >= value:
                break
        return result

    def scenic_score_horizontal(self, side, i, j):
        value = self.grid[i][j]
        result = 0
        if side == 'left':
            delta, limit = -1, -1
        elif side == 'right':
            delta, limit = 1, self.width

        for tree_index in range(j+delta, limit, delta):
            result += 1
            if self.grid[i][tree_index] >= value:
                break
        return result

def part1():
    with open(INPUT_FILENAME) as input_file:
        grid = input_file.readlines()
    forest = Forest([row.strip('\n ') for row in grid])
    print(forest.count_visible_trees())

def part2():
    with open(INPUT_FILENAME) as input_file:
        grid = input_file.readlines()
    forest = Forest([row.strip('\n ') for row in grid])
    print(forest.get_highest_scenic_score())

if __name__ == '__main__':
    part1()
    part2()