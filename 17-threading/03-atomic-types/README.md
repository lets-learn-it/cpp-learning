# Atomic Types

- On x86, all integer operations are atomic provided data is correctly aligned and fits into single word.
- This means that thread cannot be interrupted while performing integer operations
- but still we need locks because incrementing integer is fetch, decode and then increment.



