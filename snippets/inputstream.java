File file = new File(...);
InputStream is = new InputStream(file);
byte buf[] = new byte[(int)file.length()];
is.read(buf);
is.close();
System.out.println(new String(buf));

// 一个字节一个字节来
int temp;
while ((temp=is.read()) != -1) {
    buf[len++] = (byte)temp;
}

byte b[] = str.getBytes();
