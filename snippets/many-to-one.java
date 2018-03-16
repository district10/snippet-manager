// item
@ManyToOne(fetch = FetchType.EAGER, cascade = CascadeType.ALL)
@JoinColumn(name = "item_id")
private Item item;

// cart
@OneToMany(cascade = CascadeType.ALL, mappedBy = "item")
private List<Item> items;
