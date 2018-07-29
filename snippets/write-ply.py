def write_ply_lines(lines, out_path):
    strings = ["ply", "format ascii 1.0", "element vertex {}".format(len(lines)),
               "property float x", "property float y", "property float z",
               "property uint8 red", "property uint8 green", "property uint8 blue", "end_header"]
    strings.extend([" ".join([str(x) for x in line]) for line in lines])
    text = "\n".join(strings)
    with open(out_path, "w") as f:
        f.write(text)
        f.write("\n")
