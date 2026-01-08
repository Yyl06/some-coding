import os

folder = "path/to/directory"
list = sorted(os.listdir(folder))

for i, f in enumerate(list, start = 1):
    splited = os.path.splitext(f)[1] #split the fucking text from the .extension(.png)
    new_name = f"{i}{splited}"
    os.rename(os.path.join(folder, f), os.path.join(folder, new_name))