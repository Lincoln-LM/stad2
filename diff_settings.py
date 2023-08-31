def apply(config, args):
    config["baseimg"] = f"baserom.z64"
    config["myimg"] = f"pokemonstadium2.z64"
    config["mapfile"] = f"build/pokemonstadium2.map"
    config["source_directories"] = [
        "src",
        f"asm",
        "include",
        f"assets",
    ]
    config["make_command"] = ["make"]
    config["objdump_flags"] = ["-M", "reg-names=32"]
    config["expected_dir"] = f"expected"