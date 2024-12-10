import csv
import os
import re

def read_csv_to_grid(filepath):
    """Reads a CSV file and converts it to a 2D list."""
    grid = []
    with open(filepath, newline='') as csvfile:
        reader = csv.reader(csvfile, delimiter=' ')  # Adjust delimiter if needed
        for row in reader:
            grid.append([int(value) for value in row])
    return grid

def find_position(grid):
    """Finds the position of '1' in the grid."""
    for i, row in enumerate(grid):
        for j, value in enumerate(row):
            if value == 1:
                return (i, j)
    return None

#left 0 right 1 up 2 down 3
def calculate_actions(positions):
    """Calculates the actions based on the positions."""
    actions = []
    for (x1, y1), (x2, y2) in zip(positions, positions[1:]):
        if x2 == x1 - 1 and y2 == y1:
            actions.append(2)
        elif x2 == x1 + 1 and y2 == y1:
            actions.append(3)
        elif x2 == x1 and y2 == y1 - 1:
            actions.append(0)
        elif x2 == x1 and y2 == y1 + 1:
            actions.append(1)
    return actions

def natural_sort_key(filename):
    match = re.search(r'\d+', filename) 
    return int(match.group()) if match else 0

def process_snapshots(snapshot_folder):
    """Processes all snapshots in a folder and returns the sequence of actions."""
    # Get list of CSV files sorted by name (assuming they are named sequentially)
    csv_files = [f for f in os.listdir(snapshot_folder) if f.endswith('.csv')]
    csv_files.sort(key=natural_sort_key)
    #print(csv_files)
    positions = []

    # Read each CSV file and find the position of '1'
    for csv_file in csv_files:
        grid = read_csv_to_grid(os.path.join(snapshot_folder, csv_file))
        position = find_position(grid)
        if position is not None:
            positions.append(position)

    # Calculate actions based on positions
    return calculate_actions(positions)

# Example Usage
if __name__ == "__main__":
    snapshot_folder = "data/stairs1/snapshot"  # Replace with your folder path
    actions = process_snapshots(snapshot_folder)
    print("Actions:", actions)
