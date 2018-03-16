@Repository
public interface SomeRepository extends JpaRepository<SomeEntity, Long> {
    List<SomeEntity> findByValue(String value);

    @Modifying
    @Query("UPDATE SomeEntity se SET se.available=TRUE WHERE se.available=FALSE")
    void turnOn();

    @Query(value = "SELECT * FROM table WHERE part_type = :type LIMIT :limit", nativeQuery = true)
    List<Product> findWithFuzzyMatch(@Param("type") String type, @Param("limit") int limit);
}
