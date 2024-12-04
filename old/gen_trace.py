import numpy as np
import os

def generate_trace_with_path(grid_size, coordinates, output_dir):
    """
    Generate a trace of 2D grids to visit a sequence of coordinates in order.

    :param grid_size: Tuple (rows, cols) specifying the dimensions of the grid.
    :param coordinates: List of (row, col) tuples specifying the sequence to visit.
    :param output_dir: Directory where snapshots will be saved.
    """
    # Ensure the output directory exists
    if os.path.exists(output_dir):
        os.removedirs(output_dir)
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
    
    # Initialize the grid with zeros
    grid = np.zeros(grid_size, dtype=int)
    
    # Current position starts at the first coordinate
    current_position = coordinates[0]
    time_step = 1

    for target_position in coordinates:
        while current_position != target_position:
            # Clear the grid
            grid.fill(0)

            # Mark the current position on the grid
            grid[current_position] = 1

            # Save the snapshot
            snapshot_filename = os.path.join(output_dir, f"snapshot_{time_step}.csv")
            np.savetxt(snapshot_filename, grid, fmt="%d")
            print(f"Saved snapshot {time_step} to {snapshot_filename}")

            # Move one step towards the target position (up, down, left, or right)
            row_diff = target_position[0] - current_position[0]
            col_diff = target_position[1] - current_position[1]

            if row_diff > 0:  # Move down
                current_position = (current_position[0] + 1, current_position[1])
            elif row_diff < 0:  # Move up
                current_position = (current_position[0] - 1, current_position[1])
            elif col_diff > 0:  # Move right
                current_position = (current_position[0], current_position[1] + 1)
            elif col_diff < 0:  # Move left
                current_position = (current_position[0], current_position[1] - 1)
            
            time_step += 1

    # Final step: Save the grid at the last target position
    grid.fill(0)
    grid[current_position] = 1
    snapshot_filename = os.path.join(output_dir, f"snapshot_{time_step}.csv")
    np.savetxt(snapshot_filename, grid, fmt="%d")
    print(f"Saved final snapshot {time_step} to {snapshot_filename}")

# Example usage
if __name__ == "__main__":
    # Define the grid size
    grid_size = (10, 10)  # 10x10 grid

    # Input sequence of coordinates to visit
    coordinates = [(0, 0), (0, 5), (5, 5), (5,0), (0,0)]

    # Generate the path and snapshots
    generate_trace_with_path(grid_size, coordinates, "snapshots/circle")
