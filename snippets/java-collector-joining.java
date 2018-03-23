List<Integer> numbers = Arrays.asList( 4, 8, 15, 16, 23, 42 );
numbers.stream()
    .map( n -> n.toString() )
    .collect( Collectors.joining( "," ) );  

class Arrays {
    public static <T> List<T> asList(T... a) {
        return new ArrayList<>(a);
    }
}
