INPUT_FILENAME = 'input.txt'

class Ship:
    def __init__(self):
        self.stacks = []
        self.buffer = []

    def add_to_buffer(self, line):
        if not line.startswith(' 1'):
            self.buffer.append(line)
            return
        else:
            self.unload(line)

    def unload(self, line):
        self.stacks = [[] for _ in line.replace('   ', ' ').strip(' \n').split(' ')]

        for line in self.buffer:
            for i in range(0, len(line)-3, 4):
                if (crate := line[i+1]) != ' ':
                    self.stacks[i//4].insert(0, crate)

    def print_result(self):
        for stack in self.stacks:
            print(f'{stack[-1]}', end='')
        print()

class ShipWithCrane9000(Ship):
    def move(self, instruction):
        _, qntt, _, src, _, dst = instruction.split(' ')
        qntt, src, dst = int(qntt), int(src)-1, int(dst)-1
        
        for _ in range(qntt):
            self.stacks[dst].append(self.stacks[src].pop())

class ShipWithCrane9001(Ship):
    def move(self, instruction):
        _, qntt, _, src, _, dst = instruction.split(' ')
        qntt, src, dst = int(qntt), int(src)-1, int(dst)-1
        
        self.stacks[dst].extend(self.stacks[src][-qntt:])
        self.stacks[src] = self.stacks[src][:-qntt]

def part_any(ship):
    with open(INPUT_FILENAME) as input_file:
        for line in input_file:
            if (not line.startswith('move')):
                ship.add_to_buffer(line)
            elif line == '\n':
                continue;
            else:
                ship.move(line)

    ship.print_result()

if __name__ == '__main__':
    part_any(ShipWithCrane9000())
    part_any(ShipWithCrane9001())
