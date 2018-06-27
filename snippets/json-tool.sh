cat file.json | python -m json.tool
function lintjson {
    for i in *.json; do echo linting "$i"; python -m json.tool $i > bak_$i && mv bak_$i $i; done
}
