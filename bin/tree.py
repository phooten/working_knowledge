import os

# TODO: Get a better example
# TODO: Move to proper location for python
# TODO: Ignore the following directories:
        # .DS_Store
        # .git

def print_tree(start_path: str, prefix: str = "") -> None:
    """Recursively print a directory tree structure."""
    # Get all entries in the directory
    entries = sorted(os.listdir(start_path))
    entries_count = len(entries)

    for index, entry in enumerate(entries):
        path = os.path.join(start_path, entry)
        connector = "└── " if index == entries_count - 1 else "├── "
        print(prefix + connector + entry)

        # If entry is a directory, recurse into it
        if os.path.isdir(path):
            extension = "    " if index == entries_count - 1 else "│   "
            print_tree(path, prefix + extension)


def main():
    # Print current working directory
    current_dir = os.getcwd()
    print(f"\n📍 Current Location: {current_dir}\n")
    print("Directory Report (similar to `tree`):")
    print(current_dir)

    # Print directory tree
    print_tree(current_dir)


if __name__ == "__main__":
    main()