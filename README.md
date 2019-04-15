# Rainforest hash module for Python

This package implements the [Rainforest](https://github.com/bschn2/rainforest) hashing algorithms.

## Usage

```python
    import rainforest_hash
    data = '\x00'
    digest_v1 = rainforest.get(data, len(data))
    digest_v2 = rainforest.get_v2(data, len(data))
```
