// order repo
@OneToMany(cascade = CascadeType.ALL, fetch = FetchType.LAZY)
@OrderBy
@JoinColumn(name = "orderId")
@Fetch(FetchMode.SUBSELECT)
private List<Comments> comments;

// comments repo
@Getter
@Setter
@Entity
@Builder
@AllArgsConstructor
@NoArgsConstructor
@Table(name = "comments")
public class Comments {
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;
    private Long orderId;
    private String comments;
}
