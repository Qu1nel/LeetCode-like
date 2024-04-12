def flatten_dict(d: dict) -> dict[str, int]:
    new_d = {}

    for key, value in d.items():
        if isinstance(value, int):
            new_d[key] = value

        if isinstance(value, dict):
            for new_key, number in tuple(flatten_dict(value).items()):
                new_d[f'{key}_{new_key}'] = number

    return new_d


nested = {'Germany': {'berlin': 7}, 'Europe': {'italy': {'Rome': 3}}, 'USA': {'washington': 1, 'New York': 4}}
#nested = {'Q': {'w': {'E': {'r': {'T': {'y': 123}}}}}}

print(flatten_dict(nested))  # {'Germany_berlin': 7, 'Europe_italy_Rome': 3, 'USA_washington': 1, 'USA_New York': 4}
