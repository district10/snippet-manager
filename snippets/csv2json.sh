# csv to json
python -c "import csv,json;print json.dumps(list(csv.reader(open('csv_file.csv'))))"
