import rainforest_hash

header = bytes.fromhex("000000203925e0a940a13beaadba13c8a94c93f1b020a966867bc1334a8f5fdc8c000000b41136b86741ba61ade8e73f3740ffb012564c045c9ee2f2dcd418f29ce47b11e1c36f5cffff001e00124b98")

result_v1 = rainforest_hash.get(header, 80)
result_v2 = rainforest_hash.get_v2(header, 80)

assert(result_v1 == b'\x15|N\xb3\x89!\xc1Ab\xf0\x14\x04\xad\xf0aJ\xd4\x8d\xdfu\xab}^\xc1\xa8I]f%\x00\x00\x00')
assert(result_v2 == b'>ct\x1b \x9f\xeaH#\x96\x11v\xfdp\xe4m\xac\xbbl\xd2\x82\xbe\xf0B\x05\x96\xad\xbb\x83\xe2\xd87')

print(rainforest_hash.get(header, 80)[::-1].hex())
print(rainforest_hash.get_v2(header, 80)[::-1].hex())
