List<String> list = Files.readAllLines(new File("input.txt").toPath(), Charset.defaultCharset() );

String content = new Scanner(new File("filename")).useDelimiter("\\Z").next();
System.out.println(content);

Scanner s = new Scanner(new File("filepath"));
ArrayList<String> list = new ArrayList<String>();
while (s.hasNext()){
    // list.add(s.next()); // word
    list.add(s.nextLine()); // line
}
s.close();
