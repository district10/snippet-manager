LocalDate localDate = new SimpleDateFormat("yyyy/MM/dd").parse("2018/03/10")
        .toInstant().atZone(ZoneId.systemDefault()).toLocalDate();
System.out.println(localDate.plusDays(2)); // 2018-03-12
System.out.println(localDate.plusDays(3)); // 2018-03-13
System.out.println(localDate.plusDays(5)); // 2018-03-15
