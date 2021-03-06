set(PACKAGE_NAME test-hdr)

set(CDS_TESTHDR_MAP
    map/hdr_michael_map_hp.cpp
    map/hdr_michael_map_dhp.cpp
    map/hdr_michael_map_rcu_gpi.cpp
    map/hdr_michael_map_rcu_gpb.cpp
    map/hdr_michael_map_rcu_gpt.cpp
    map/hdr_michael_map_rcu_shb.cpp
    map/hdr_michael_map_rcu_sht.cpp
    map/hdr_michael_map_nogc.cpp
    map/hdr_michael_map_lazy_hp.cpp
    map/hdr_michael_map_lazy_dhp.cpp
    map/hdr_michael_map_lazy_rcu_gpi.cpp
    map/hdr_michael_map_lazy_rcu_gpb.cpp
    map/hdr_michael_map_lazy_rcu_gpt.cpp
    map/hdr_michael_map_lazy_rcu_shb.cpp
    map/hdr_michael_map_lazy_rcu_sht.cpp
    map/hdr_michael_map_lazy_nogc.cpp
    map/hdr_feldman_hashmap_hp.cpp
    map/hdr_feldman_hashmap_dhp.cpp
    map/hdr_feldman_hashmap_rcu_gpb.cpp
    map/hdr_feldman_hashmap_rcu_gpi.cpp
    map/hdr_feldman_hashmap_rcu_gpt.cpp
    map/hdr_feldman_hashmap_rcu_shb.cpp
    map/hdr_feldman_hashmap_rcu_sht.cpp
    map/hdr_refinable_hashmap_hashmap_std.cpp
    map/hdr_refinable_hashmap_boost_list.cpp
    map/hdr_refinable_hashmap_list.cpp
    map/hdr_refinable_hashmap_map.cpp
    map/hdr_refinable_hashmap_boost_map.cpp
    map/hdr_refinable_hashmap_boost_flat_map.cpp
    map/hdr_refinable_hashmap_boost_unordered_map.cpp
    map/hdr_refinable_hashmap_slist.cpp
    map/hdr_skiplist_map_hp.cpp
    map/hdr_skiplist_map_dhp.cpp
    map/hdr_skiplist_map_rcu_gpi.cpp
    map/hdr_skiplist_map_rcu_gpb.cpp
    map/hdr_skiplist_map_rcu_gpt.cpp
    map/hdr_skiplist_map_rcu_shb.cpp
    map/hdr_skiplist_map_rcu_sht.cpp
    map/hdr_skiplist_map_nogc.cpp
    map/hdr_splitlist_map_hp.cpp
    map/hdr_splitlist_map_dhp.cpp
    map/hdr_splitlist_map_nogc.cpp
    map/hdr_splitlist_map_rcu_gpi.cpp
    map/hdr_splitlist_map_rcu_gpb.cpp
    map/hdr_splitlist_map_rcu_gpt.cpp
    map/hdr_splitlist_map_rcu_shb.cpp
    map/hdr_splitlist_map_rcu_sht.cpp
    map/hdr_splitlist_map_lazy_hp.cpp
    map/hdr_splitlist_map_lazy_dhp.cpp
    map/hdr_splitlist_map_lazy_nogc.cpp
    map/hdr_splitlist_map_lazy_rcu_gpi.cpp
    map/hdr_splitlist_map_lazy_rcu_gpb.cpp
    map/hdr_splitlist_map_lazy_rcu_gpt.cpp
    map/hdr_splitlist_map_lazy_rcu_sht.cpp
    map/hdr_splitlist_map_lazy_rcu_shb.cpp
    map/hdr_striped_hashmap_hashmap_std.cpp
    map/hdr_striped_hashmap_boost_list.cpp
    map/hdr_striped_hashmap_list.cpp
    map/hdr_striped_hashmap_map.cpp
    map/hdr_striped_hashmap_boost_map.cpp
    map/hdr_striped_hashmap_boost_flat_map.cpp
    map/hdr_striped_hashmap_boost_unordered_map.cpp
    map/hdr_striped_hashmap_slist.cpp
    map/hdr_striped_map_reg.cpp)

set(CDS_TESTHDR_DEQUE
    deque/hdr_fcdeque.cpp)

set(CDS_TESTHDR_LIST
    list/hdr_lazy_dhp.cpp
    list/hdr_lazy_hp.cpp
    list/hdr_lazy_nogc.cpp
    list/hdr_lazy_nogc_unord.cpp
    list/hdr_lazy_rcu_gpi.cpp
    list/hdr_lazy_rcu_gpb.cpp
    list/hdr_lazy_rcu_gpt.cpp
    list/hdr_lazy_rcu_shb.cpp
    list/hdr_lazy_rcu_sht.cpp
    list/hdr_lazy_kv_dhp.cpp
    list/hdr_lazy_kv_hp.cpp
    list/hdr_lazy_kv_nogc.cpp
    list/hdr_lazy_kv_nogc_unord.cpp
    list/hdr_lazy_kv_rcu_gpb.cpp
    list/hdr_lazy_kv_rcu_gpi.cpp
    list/hdr_lazy_kv_rcu_gpt.cpp
    list/hdr_lazy_kv_rcu_shb.cpp
    list/hdr_lazy_kv_rcu_sht.cpp
    list/hdr_michael_dhp.cpp
    list/hdr_michael_hp.cpp
    list/hdr_michael_nogc.cpp
    list/hdr_michael_rcu_gpi.cpp
    list/hdr_michael_rcu_gpb.cpp
    list/hdr_michael_rcu_gpt.cpp
    list/hdr_michael_rcu_shb.cpp
    list/hdr_michael_rcu_sht.cpp
    list/hdr_michael_kv_dhp.cpp
    list/hdr_michael_kv_hp.cpp
    list/hdr_michael_kv_nogc.cpp
    list/hdr_michael_kv_rcu_gpi.cpp
    list/hdr_michael_kv_rcu_gpb.cpp
    list/hdr_michael_kv_rcu_gpt.cpp
    list/hdr_michael_kv_rcu_shb.cpp
    list/hdr_michael_kv_rcu_sht.cpp)

set(CDS_TESTHDR_PQUEUE
    priority_queue/hdr_intrusive_mspqueue_dyn.cpp
    priority_queue/hdr_intrusive_mspqueue_static.cpp
    priority_queue/hdr_mspqueue_dyn.cpp
    priority_queue/hdr_mspqueue_static.cpp
    priority_queue/hdr_fcpqueue_boost_stable_vector.cpp
    priority_queue/hdr_fcpqueue_deque.cpp
    priority_queue/hdr_fcpqueue_vector.cpp
    priority_queue/hdr_priority_queue_reg.cpp)

set(CDS_TESTHDR_QUEUE
    queue/hdr_queue_register.cpp
    queue/hdr_intrusive_fcqueue.cpp
    queue/hdr_intrusive_segmented_queue_hp.cpp
    queue/hdr_intrusive_segmented_queue_dhp.cpp
    queue/hdr_intrusive_tsigas_cycle_queue.cpp
    queue/hdr_intrusive_vyukovmpmc_cycle_queue.cpp
    queue/hdr_basketqueue_hp.cpp
    queue/hdr_basketqueue_dhp.cpp
    queue/hdr_fcqueue.cpp
    queue/hdr_moirqueue_hp.cpp
    queue/hdr_moirqueue_dhp.cpp
    queue/hdr_msqueue_hp.cpp
    queue/hdr_msqueue_dhp.cpp
    queue/hdr_optimistic_hp.cpp
    queue/hdr_optimistic_dhp.cpp
    queue/hdr_rwqueue.cpp
    queue/hdr_segmented_queue_hp.cpp
    queue/hdr_segmented_queue_dhp.cpp
    queue/hdr_tsigas_cycle_queue.cpp
    queue/hdr_vyukov_mpmc_cyclic.cpp)

set(CDS_TESTHDR_SET
    set/hdr_intrusive_feldman_hashset_hp.cpp
    set/hdr_intrusive_feldman_hashset_dhp.cpp
    set/hdr_intrusive_feldman_hashset_rcu_gpi.cpp
    set/hdr_intrusive_feldman_hashset_rcu_gpb.cpp
    set/hdr_intrusive_feldman_hashset_rcu_gpt.cpp
    set/hdr_intrusive_feldman_hashset_rcu_shb.cpp
    set/hdr_intrusive_feldman_hashset_rcu_sht.cpp
    set/hdr_intrusive_refinable_hashset_avlset.cpp
    set/hdr_intrusive_refinable_hashset_list.cpp
    set/hdr_intrusive_refinable_hashset_set.cpp
    set/hdr_intrusive_refinable_hashset_sgset.cpp
    set/hdr_intrusive_refinable_hashset_slist.cpp
    set/hdr_intrusive_refinable_hashset_splayset.cpp
    set/hdr_intrusive_refinable_hashset_treapset.cpp
    set/hdr_intrusive_refinable_hashset_uset.cpp
    set/hdr_intrusive_skiplist_hp.cpp
    set/hdr_intrusive_skiplist_dhp.cpp
    set/hdr_intrusive_skiplist_rcu_gpb.cpp
    set/hdr_intrusive_skiplist_rcu_gpi.cpp
    set/hdr_intrusive_skiplist_rcu_gpt.cpp
    set/hdr_intrusive_skiplist_rcu_shb.cpp
    set/hdr_intrusive_skiplist_rcu_sht.cpp
    set/hdr_intrusive_skiplist_nogc.cpp
    set/hdr_intrusive_striped_hashset_avlset.cpp
    set/hdr_intrusive_striped_hashset_list.cpp
    set/hdr_intrusive_striped_hashset_set.cpp
    set/hdr_intrusive_striped_hashset_sgset.cpp
    set/hdr_intrusive_striped_hashset_slist.cpp
    set/hdr_intrusive_striped_hashset_splayset.cpp
    set/hdr_intrusive_striped_hashset_treapset.cpp
    set/hdr_intrusive_striped_hashset_uset.cpp
    set/hdr_intrusive_striped_set.cpp
    set/hdr_michael_set_hp.cpp
    set/hdr_michael_set_dhp.cpp
    set/hdr_michael_set_rcu_gpi.cpp
    set/hdr_michael_set_rcu_gpb.cpp
    set/hdr_michael_set_rcu_gpt.cpp
    set/hdr_michael_set_rcu_shb.cpp
    set/hdr_michael_set_rcu_sht.cpp
    set/hdr_michael_set_nogc.cpp
    set/hdr_michael_set_lazy_hp.cpp
    set/hdr_michael_set_lazy_dhp.cpp
    set/hdr_michael_set_lazy_rcu_gpi.cpp
    set/hdr_michael_set_lazy_rcu_gpb.cpp
    set/hdr_michael_set_lazy_rcu_gpt.cpp
    set/hdr_michael_set_lazy_rcu_shb.cpp
    set/hdr_michael_set_lazy_rcu_sht.cpp
    set/hdr_michael_set_lazy_nogc.cpp
    set/hdr_feldman_hashset_hp.cpp
    set/hdr_feldman_hashset_dhp.cpp
    set/hdr_feldman_hashset_rcu_gpb.cpp
    set/hdr_feldman_hashset_rcu_gpi.cpp
    set/hdr_feldman_hashset_rcu_gpt.cpp
    set/hdr_feldman_hashset_rcu_shb.cpp
    set/hdr_feldman_hashset_rcu_sht.cpp
    set/hdr_refinable_hashset_hashset_std.cpp
    set/hdr_refinable_hashset_boost_flat_set.cpp
    set/hdr_refinable_hashset_boost_list.cpp
    set/hdr_refinable_hashset_boost_set.cpp
    set/hdr_refinable_hashset_boost_stable_vector.cpp
    set/hdr_refinable_hashset_boost_unordered_set.cpp
    set/hdr_refinable_hashset_boost_vector.cpp
    set/hdr_refinable_hashset_list.cpp
    set/hdr_refinable_hashset_set.cpp
    set/hdr_refinable_hashset_slist.cpp
    set/hdr_refinable_hashset_vector.cpp
    set/hdr_skiplist_set_hp.cpp
    set/hdr_skiplist_set_dhp.cpp
    set/hdr_skiplist_set_rcu_gpi.cpp
    set/hdr_skiplist_set_rcu_gpb.cpp
    set/hdr_skiplist_set_rcu_gpt.cpp
    set/hdr_skiplist_set_rcu_shb.cpp
    set/hdr_skiplist_set_rcu_sht.cpp
    set/hdr_skiplist_set_nogc.cpp
    set/hdr_splitlist_set_hp.cpp
    set/hdr_splitlist_set_nogc.cpp
    set/hdr_splitlist_set_dhp.cpp
    set/hdr_splitlist_set_rcu_gpi.cpp
    set/hdr_splitlist_set_rcu_gpb.cpp
    set/hdr_splitlist_set_rcu_gpt.cpp
    set/hdr_splitlist_set_rcu_shb.cpp
    set/hdr_splitlist_set_rcu_sht.cpp
    set/hdr_splitlist_set_lazy_hp.cpp
    set/hdr_splitlist_set_lazy_nogc.cpp
    set/hdr_splitlist_set_lazy_dhp.cpp
    set/hdr_splitlist_set_lazy_rcu_gpi.cpp
    set/hdr_splitlist_set_lazy_rcu_gpb.cpp
    set/hdr_splitlist_set_lazy_rcu_gpt.cpp
    set/hdr_splitlist_set_lazy_rcu_shb.cpp
    set/hdr_splitlist_set_lazy_rcu_sht.cpp
    set/hdr_striped_hashset_hashset_std.cpp
    set/hdr_striped_hashset_boost_flat_set.cpp
    set/hdr_striped_hashset_boost_list.cpp
    set/hdr_striped_hashset_boost_set.cpp
    set/hdr_striped_hashset_boost_stable_vector.cpp
    set/hdr_striped_hashset_boost_unordered_set.cpp
    set/hdr_striped_hashset_boost_vector.cpp
    set/hdr_striped_hashset_list.cpp
    set/hdr_striped_hashset_set.cpp
    set/hdr_striped_hashset_slist.cpp
    set/hdr_striped_hashset_vector.cpp)

set(CDS_TESTHDR_STACK
    stack/hdr_intrusive_fcstack.cpp
    stack/hdr_treiber_stack_hp.cpp
    stack/hdr_treiber_stack_dhp.cpp
    stack/hdr_elimination_stack_hp.cpp
    stack/hdr_elimination_stack_dhp.cpp
    stack/hdr_fcstack.cpp)

set(CDS_TESTHDR_TREE
    tree/hdr_tree_reg.cpp
    tree/hdr_intrusive_ellen_bintree_hp.cpp
    tree/hdr_intrusive_ellen_bintree_dhp.cpp
    tree/hdr_intrusive_ellen_bintree_rcu_gpb.cpp
    tree/hdr_intrusive_ellen_bintree_rcu_gpi.cpp
    tree/hdr_intrusive_ellen_bintree_rcu_gpt.cpp
    tree/hdr_intrusive_ellen_bintree_rcu_shb.cpp
    tree/hdr_intrusive_ellen_bintree_rcu_sht.cpp
    tree/hdr_ellenbintree_map_hp.cpp
    tree/hdr_ellenbintree_map_dhp.cpp
    tree/hdr_ellenbintree_map_rcu_gpb.cpp
    tree/hdr_ellenbintree_map_rcu_gpi.cpp
    tree/hdr_ellenbintree_map_rcu_gpt.cpp
    tree/hdr_ellenbintree_map_rcu_shb.cpp
    tree/hdr_ellenbintree_map_rcu_sht.cpp
    tree/hdr_ellenbintree_set_hp.cpp
    tree/hdr_ellenbintree_set_dhp.cpp
    tree/hdr_ellenbintree_set_rcu_gpb.cpp
    tree/hdr_ellenbintree_set_rcu_gpi.cpp
    tree/hdr_ellenbintree_set_rcu_gpt.cpp
    tree/hdr_ellenbintree_set_rcu_shb.cpp
    tree/hdr_ellenbintree_set_rcu_sht.cpp
    tree/hdr_bronson_avltree_map_rcu_gpb.cpp
    tree/hdr_bronson_avltree_map_rcu_gpb_pool_monitor.cpp
    tree/hdr_bronson_avltree_map_rcu_gpi.cpp
    tree/hdr_bronson_avltree_map_rcu_gpi_pool_monitor.cpp
    tree/hdr_bronson_avltree_map_rcu_gpt.cpp
    tree/hdr_bronson_avltree_map_rcu_gpt_pool_monitor.cpp
    tree/hdr_bronson_avltree_map_rcu_shb.cpp
    tree/hdr_bronson_avltree_map_rcu_shb_pool_monitor.cpp
    tree/hdr_bronson_avltree_map_rcu_sht.cpp
    tree/hdr_bronson_avltree_map_rcu_sht_pool_monitor.cpp
   )

set(CDS_TESTHDR_MISC
    misc/cxx11_atomic_class.cpp
    misc/cxx11_atomic_func.cpp
    misc/find_option.cpp
    misc/allocator_test.cpp
    misc/michael_allocator.cpp
    misc/hash_tuple.cpp
    misc/bitop_st.cpp
    misc/split_bitstring.cpp
    misc/permutation_generator.cpp
    misc/thread_init_fini.cpp)

set(CDS_TESTHDR_OFFSETOF_MAP
    map/hdr_cuckoo_map.cpp)

set(CDS_TESTHDR_OFFSETOF_SET
    set/hdr_cuckoo_set.cpp
    set/hdr_intrusive_cuckoo_set.cpp
    set/hdr_intrusive_cuckoo_refinable_set.cpp
    set/hdr_intrusive_michael_set_hp.cpp
    set/hdr_intrusive_michael_set_dhp.cpp
    set/hdr_intrusive_michael_set_nogc.cpp
    set/hdr_intrusive_michael_set_rcu_gpi.cpp
    set/hdr_intrusive_michael_set_rcu_gpb.cpp
    set/hdr_intrusive_michael_set_rcu_gpt.cpp
    set/hdr_intrusive_michael_set_rcu_shb.cpp
    set/hdr_intrusive_michael_set_rcu_sht.cpp
    set/hdr_intrusive_michael_set_hp_lazy.cpp
    set/hdr_intrusive_michael_set_dhp_lazy.cpp
    set/hdr_intrusive_michael_set_nogc_lazy.cpp
    set/hdr_intrusive_michael_set_rcu_gpi_lazy.cpp
    set/hdr_intrusive_michael_set_rcu_gpb_lazy.cpp
    set/hdr_intrusive_michael_set_rcu_gpt_lazy.cpp
    set/hdr_intrusive_michael_set_rcu_shb_lazy.cpp
    set/hdr_intrusive_michael_set_rcu_sht_lazy.cpp
    set/hdr_intrusive_skiplist_hp_member.cpp
    set/hdr_intrusive_skiplist_dhp_member.cpp
    set/hdr_intrusive_skiplist_rcu_gpi_member.cpp
    set/hdr_intrusive_skiplist_rcu_gpb_member.cpp
    set/hdr_intrusive_skiplist_rcu_gpt_member.cpp
    set/hdr_intrusive_skiplist_rcu_shb_member.cpp
    set/hdr_intrusive_skiplist_rcu_sht_member.cpp
    set/hdr_intrusive_skiplist_nogc_member.cpp
    set/hdr_intrusive_splitlist_set_hp.cpp
    set/hdr_intrusive_splitlist_set_nogc.cpp
    set/hdr_intrusive_splitlist_set_dhp.cpp
    set/hdr_intrusive_splitlist_set_rcu_gpb.cpp
    set/hdr_intrusive_splitlist_set_rcu_gpi.cpp
    set/hdr_intrusive_splitlist_set_rcu_gpt.cpp
    set/hdr_intrusive_splitlist_set_rcu_shb.cpp
    set/hdr_intrusive_splitlist_set_rcu_sht.cpp
    set/hdr_intrusive_splitlist_set_hp_lazy.cpp
    set/hdr_intrusive_splitlist_set_nogc_lazy.cpp
    set/hdr_intrusive_splitlist_set_dhp_lazy.cpp
    set/hdr_intrusive_splitlist_set_rcu_gpb_lazy.cpp
    set/hdr_intrusive_splitlist_set_rcu_gpi_lazy.cpp
    set/hdr_intrusive_splitlist_set_rcu_gpt_lazy.cpp
    set/hdr_intrusive_splitlist_set_rcu_shb_lazy.cpp
    set/hdr_intrusive_splitlist_set_rcu_sht_lazy.cpp)

set(CDS_TESTHDR_OFFSETOF_LIST
    list/hdr_intrusive_lazy_dhp.cpp
    list/hdr_intrusive_lazy_hp.cpp
    list/hdr_intrusive_lazy_nogc.cpp
    list/hdr_intrusive_lazy_nogc_unord.cpp
    list/hdr_intrusive_lazy_rcu_gpb.cpp
    list/hdr_intrusive_lazy_rcu_gpi.cpp
    list/hdr_intrusive_lazy_rcu_gpt.cpp
    list/hdr_intrusive_lazy_rcu_shb.cpp
    list/hdr_intrusive_lazy_rcu_sht.cpp
    list/hdr_intrusive_michael_dhp.cpp
    list/hdr_intrusive_michael_hp.cpp
    list/hdr_intrusive_michael_nogc.cpp
    list/hdr_intrusive_michael_list_rcu_gpb.cpp
    list/hdr_intrusive_michael_list_rcu_gpi.cpp
    list/hdr_intrusive_michael_list_rcu_gpt.cpp
    list/hdr_intrusive_michael_list_rcu_shb.cpp
    list/hdr_intrusive_michael_list_rcu_sht.cpp)

set(CDS_TESTHDR_OFFSETOF_QUEUE
    queue/hdr_intrusive_basketqueue_hp.cpp
    queue/hdr_intrusive_basketqueue_dhp.cpp
    queue/hdr_intrusive_moirqueue_hp.cpp
    queue/hdr_intrusive_moirqueue_dhp.cpp
    queue/hdr_intrusive_msqueue_hp.cpp
    queue/hdr_intrusive_msqueue_dhp.cpp
    queue/hdr_intrusive_optimisticqueue_hp.cpp
    queue/hdr_intrusive_optimisticqueue_dhp.cpp)

set(CDS_TESTHDR_OFFSETOF_STACK
    stack/hdr_intrusive_treiber_stack_hp.cpp
    stack/hdr_intrusive_treiber_stack_dhp.cpp
    stack/hdr_intrusive_elimination_stack_hp.cpp
    stack/hdr_intrusive_elimination_stack_dhp.cpp)

set(CDS_TESTHDR_OFFSETOF_TREE
    tree/hdr_intrusive_ellen_bintree_hp_member.cpp
    tree/hdr_intrusive_ellen_bintree_dhp_member.cpp
    tree/hdr_intrusive_ellen_bintree_rcu_gpb_member.cpp
    tree/hdr_intrusive_ellen_bintree_rcu_gpi_member.cpp
    tree/hdr_intrusive_ellen_bintree_rcu_gpt_member.cpp
    tree/hdr_intrusive_ellen_bintree_rcu_shb_member.cpp
    tree/hdr_intrusive_ellen_bintree_rcu_sht_member.cpp)

set(CDS_TESTHDR_OFFSETOF_SOURCES
	${CDS_TESTHDR_OFFSETOF_QUEUE}
	${CDS_TESTHDR_OFFSETOF_STACK}
	${CDS_TESTHDR_OFFSETOF_MAP}
	${CDS_TESTHDR_OFFSETOF_SET}
	${CDS_TESTHDR_OFFSETOF_LIST}
	${CDS_TESTHDR_OFFSETOF_TREE})

add_library(test-hdr-offsetof OBJECT ${CDS_TESTHDR_OFFSETOF_SOURCES})

if(CMAKE_COMPILER_IS_GNUCC)
  set_property(TARGET test-hdr-offsetof APPEND_STRING PROPERTY COMPILE_FLAGS -Wno-invalid-offsetof)
endif(CMAKE_COMPILER_IS_GNUCC)

set(CDS_TESTHDR_SOURCES
    ${CDS_TESTHDR_QUEUE}
    ${CDS_TESTHDR_PQUEUE}
    ${CDS_TESTHDR_STACK}
    ${CDS_TESTHDR_MAP}
    ${CDS_TESTHDR_DEQUE}
    ${CDS_TESTHDR_LIST}
    ${CDS_TESTHDR_SET}
    ${CDS_TESTHDR_TREE}
    ${CDS_TESTHDR_MISC})

add_executable(${PACKAGE_NAME} ${CDS_TESTHDR_SOURCES} $<TARGET_OBJECTS:test-hdr-offsetof> $<TARGET_OBJECTS:${TEST_COMMON}>)
target_link_libraries(${PACKAGE_NAME} ${CDS_SHARED_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME ${PACKAGE_NAME} COMMAND ${PACKAGE_NAME} WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})