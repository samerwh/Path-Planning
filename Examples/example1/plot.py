import matplotlib.pyplot as plt
import numpy as np

def map_from_file(filename, nrows, ncols):
    f = open(filename, 'r')
    row = []
    map = np.empty((0,nrows), int)

    for i in range(nrows):
        line = f.readline()
        for j in range(ncols):
            row.append(int(line.split()[j]))

        map = np.append(map, np.array([row]), axis=0)
        row.clear()
    
    return map

def draw_plots(array1, array2):

    palette = np.array([[255,   0,   0], # index 0: red
                        [255, 255, 255], # index 1: black
                        [28, 28, 31], # index 2: white
                        [255, 255, 255], # index 3: red
                        [255, 255, 255], # index 4: blue
                        [190, 58, 28], # index 5: yellow
                        [32, 229, 200], # index 6: 
                        [100, 230, 100], # index 7
                        ], dtype=np.uint8)

    fig,axes = plt.subplots(nrows=1,ncols=2,figsize=(8,4))
    axes[0].imshow(palette[array1])
    axes[0].tick_params(
        top=False, bottom=False, right=False, left=False,
        labeltop=False, labelbottom=False, labelright=False, labelleft=False)
    axes[0].set_xticks(np.arange(-0.5,39.5,1))
    axes[0].set_yticks(np.arange(-0.5,39.5,1))
    # axes[0].grid()

    axes[1].imshow(palette[array2])
    axes[1].tick_params(
        top=False, bottom=False, right=False, left=False,
        labeltop=False, labelbottom=False, labelright=False, labelleft=False)
    axes[1].set_xticks(np.arange(-0.5,39.5,1))
    axes[1].set_yticks(np.arange(-0.5,39.5,1))
    # axes[1].grid()

    plt.tight_layout()
    plt.show()

arr1 = map_from_file('map1.tmp', 40, 40)
arr2 = map_from_file('solved_map1.tmp', 40, 40)

draw_plots(arr1, arr2)
