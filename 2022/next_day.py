import os
import shutil

next_day_dir = 'day'+str(max([int(day[3:]) for day in os.listdir('.') if day.startswith('day')])+1)
os.mkdir(next_day_dir)
shutil.copy('main.py', f'{next_day_dir}/main.py')
with open(f'{next_day_dir}/input.txt', 'w') as _:
    pass
