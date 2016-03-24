#include <KokkosKernels_GraphColorHandle.hpp>
#include <KokkosKernels_GaussSeidelHandle.hpp>
#include <KokkosKernels_SPGEMMHandle.hpp>
#ifndef _KOKKOSKERNELHANDLE_HPP
#define _KOKKOSKERNELHANDLE_HPP

namespace KokkosKernels{

namespace Experimental{



template <class lno_row_view_t_, class lno_nnz_view_t_, class scalar_nnz_view_t_,
          class ExecutionSpace, class TemporaryMemorySpace, class PersistentMemorySpace>
class KokkosKernelsHandle{
public:

  typedef ExecutionSpace HandleExecSpace;
  typedef TemporaryMemorySpace HandleTempMemorySpace;
  typedef PersistentMemorySpace HandlePersistentMemorySpace;



  //typedef row_index_view_type_ in_row_index_view_type;
  //typedef lno_row_view_t_ in_row_index_view_type;
  typedef lno_row_view_t_ in_lno_row_view_t;

  //typedef nonzero_index_view_type_ idx_edge_array_type;
  //typedef lno_nnz_view_t_ in_nonzero_index_view_type;
  typedef lno_nnz_view_t_ in_lno_nnz_view_t;

  //typedef nonzero_value_view_type_ value_array_type;
  //typedef scalar_nnz_view_t_ in_nonzero_value_view_type;
  typedef scalar_nnz_view_t_ in_scalar_nnz_view_t;

  //typedef typename row_index_view_type::value_type idx;
  //typedef typename in_lno_row_view_t::non_const_value_type row_index_type;
  typedef typename in_lno_row_view_t::non_const_value_type row_lno_t;

  //typedef typename row_index_view_type::array_layout idx_array_layout;
  typedef typename in_lno_row_view_t::array_layout row_lno_view_array_layout;

  //typedef typename row_index_view_type::device_type idx_device_type;
  typedef typename in_lno_row_view_t::device_type row_lno_view_device_t;

  //typedef typename row_index_view_type::memory_traits idx_memory_traits;
  typedef typename in_lno_row_view_t::memory_traits row_lno_view_memory_traits;

  //typedef typename row_index_view_type::HostMirror host_view_type;
  typedef typename in_lno_row_view_t::HostMirror row_lno_host_view_t; //Host view type
  //typedef typename idx_memory_traits::MemorySpace MyMemorySpace;

  //typedef typename nonzero_index_view_type::value_type idx_edge;
  //typedef typename in_lno_nnz_view_t::non_const_value_type nonzero_index_type;
  typedef typename in_lno_nnz_view_t::non_const_value_type nnz_lno_t;

  //typedef typename nonzero_index_view_type::array_layout idx_edge_array_layout;
  //typedef typename in_lno_nnz_view_t::array_layout nonzero_index_view_array_layout;
  typedef typename in_lno_nnz_view_t::array_layout nnz_lno_view_array_layout;

  //typedef typename nonzero_index_view_type::device_type idx_edge_device_type;
  //typedef typename in_lno_nnz_view_t::device_type nonzero_index_view_device_type;
  typedef typename in_lno_nnz_view_t::device_type nnz_lno_view_device_t;

  //typedef typename nonzero_index_view_type::memory_traits idx_edge_memory_traits;
  //typedef typename in_lno_nnz_view_t::memory_traits nonzero_index_view_memory_traits;
  typedef typename in_lno_nnz_view_t::memory_traits nnz_lno_view_memory_traits;

  //typedef typename nonzero_index_view_type::HostMirror host_edge_view_type; //Host view type
  //typedef typename in_lno_nnz_view_t::HostMirror nonzero_index_host_view_type; //Host view type
  typedef typename in_lno_nnz_view_t::HostMirror nnz_lno_host_view_t; //Host view type


  //typedef typename nonzero_value_view_type::value_type value_type;
  //typedef typename in_scalar_nnz_view_t::non_const_value_type nonzero_value_type;
  typedef typename in_scalar_nnz_view_t::non_const_value_type nnz_scalar_t;


  //typedef typename nonzero_value_view_type::array_layout value_type_array_layout;
  //typedef typename in_scalar_nnz_view_t::array_layout nonzero_value_view_array_layout;
  typedef typename in_scalar_nnz_view_t::array_layout nnz_scalar_view_array_layout;

  //typedef typename nonzero_value_view_type::device_type value_type_device_type;
  //typedef typename in_scalar_nnz_view_t::device_type nonzero_value_view_device_type;
  typedef typename in_scalar_nnz_view_t::device_type nnz_scalar_view_device_t;

  //typedef typename nonzero_value_view_type::memory_traits value_type_memory_traits;
  //typedef typename in_scalar_nnz_view_t::memory_traits nonzero_value_view_memory_traits;
  typedef typename in_scalar_nnz_view_t::memory_traits nnz_scalar_view_memory_traits;

  //typedef typename nonzero_value_view_type::HostMirror host_value_view_type; //Host view type
  //typedef typename in_scalar_nnz_view_t::HostMirror nonzero_value_host_view_type; //Host view type
  typedef typename in_scalar_nnz_view_t::HostMirror nnz_scalar_view_t; //Host view type


  //typedef typename in_lno_row_view_t::const_data_type const_row_data_type;
  typedef typename in_lno_row_view_t::const_data_type const_row_lno_t;

  //typedef typename in_lno_row_view_t::non_const_data_type non_const_row_data_type;
  typedef typename in_lno_row_view_t::non_const_data_type non_const_row_lno_t;

  //typedef typename in_row_index_view_type::memory_space row_view_memory_space;
  //typedef typename Kokkos::View<const_row_lno_t, row_view_array_layout,
  //    row_view_device_t, row_view_memory_traits> const_row_index_view_type;

  typedef typename in_lno_row_view_t::const_type const_lno_row_view_t;

  //typedef typename Kokkos::View<non_const_row_lno_t, row_view_array_layout,
  //    row_view_device_t, row_view_memory_traits> non_const_row_index_view_type;
  typedef typename in_lno_row_view_t::non_const_type non_const_lno_row_view_t;


  //typedef typename in_lno_nnz_view_t::const_data_type const_nonzero_index_data_type;
  typedef typename in_lno_nnz_view_t::const_data_type const_nnz_lno_t;

  //typedef typename in_lno_nnz_view_t::non_const_data_type non_const_nonzero_index_data_type;
  typedef typename in_lno_nnz_view_t::non_const_data_type non_const_nnz_lno_t;


  //typedef typename in_nonzero_index_view_type::memory_space nonzero_index_view_memory_space;
  //typedef typename Kokkos::View<const_nnz_lno_t, nnz_lno_view_array_layout,
  //    nnz_lno_view_device_t, nnz_lno_view_memory_traits> const_nonzero_index_view_type;
  typedef typename in_lno_nnz_view_t::const_type const_lno_nnz_view_t;

  //typedef typename Kokkos::View<non_const_nnz_lno_t, nnz_lno_view_array_layout,
  //    nnz_lno_view_device_t, nnz_lno_view_memory_traits> non_const_nonzero_index_view_type;
  typedef typename in_lno_nnz_view_t::non_const_type non_const_lno_nnz_view_t;


  //typedef typename in_scalar_nnz_view_t::const_data_type const_nonzero_value_data_type; //nnz_scalar_t
  typedef typename in_scalar_nnz_view_t::const_data_type const_nnz_scalar_t; //nnz_scalar_t

  //typedef typename in_scalar_nnz_view_t::non_const_data_type non_const_nonzero_value_data_type;
  typedef typename in_scalar_nnz_view_t::non_const_data_type non_const_nnz_scalar_t;


  //typedef typename in_nonzero_value_view_type::memory_space nonzero_value_view_memory_space;
  //typedef typename Kokkos::View<const_nnz_scalar_t, nnz_scalar_view_array_layout,
  //      nnz_lno_view_device_t, nnz_scalar_view_memory_traits> const_nonzero_value_view_type;
  typedef typename in_scalar_nnz_view_t::const_type const_scalar_nnz_view_t;

  //typedef typename Kokkos::View<non_const_nnz_scalar_t, nnz_scalar_view_array_layout,
  //      nnz_lno_view_device_t, nnz_scalar_view_memory_traits> non_const_nonzero_value_view_type;
  typedef typename in_scalar_nnz_view_t::non_const_type non_const_scalar_nnz_view_t;

  typedef typename Graph::GraphColoringHandle
      <in_lno_row_view_t, non_const_lno_row_view_t, in_lno_nnz_view_t,
      ExecutionSpace, TemporaryMemorySpace, PersistentMemorySpace> GraphColoringHandleType;

  typedef typename Graph::GaussSeidelHandle
      <in_lno_row_view_t, in_lno_nnz_view_t, in_scalar_nnz_view_t,
      ExecutionSpace, TemporaryMemorySpace, PersistentMemorySpace> GaussSeidelHandleType;

  typedef typename Graph::SPGEMMHandle
      <in_lno_row_view_t, in_lno_nnz_view_t, in_scalar_nnz_view_t,
      ExecutionSpace, TemporaryMemorySpace, PersistentMemorySpace> SPGEMMHandleType;


  //typedef typename Kokkos::View<row_index_type *, HandleTempMemorySpace> idx_temp_work_array_type;
  //typedef typename Kokkos::View<row_lno_t *, HandleTempMemorySpace> row_index_temp_work_view_type;
  typedef typename Kokkos::View<row_lno_t *, HandleTempMemorySpace> row_lno_temp_work_view_t;

  //typedef typename Kokkos::View<row_index_type *, HandlePersistentMemorySpace> idx_persistent_work_array_type;
  //typedef typename Kokkos::View<row_lno_t *, HandlePersistentMemorySpace> row_index_persistent_work_view_type;
  typedef typename Kokkos::View<row_lno_t *, HandlePersistentMemorySpace> row_lno_persistent_work_view_t;

  //typedef typename row_index_persistent_work_view_type::HostMirror host_idx_persistent_view_type; //Host view type
  //typedef typename lno_persistent_work_view_t::HostMirror row_index_persistent_host_view_type; //Host view type
  typedef typename row_lno_persistent_work_view_t::HostMirror row_lno_persistent_work_host_view_t; //Host view type

  //typedef typename Kokkos::View<nonzero_value_type *, HandleTempMemorySpace> value_temp_work_array_type;
  //typedef typename Kokkos::View<nnz_scalar_t *, HandleTempMemorySpace> nonzero_value_temp_work_view_type;
  typedef typename Kokkos::View<nnz_scalar_t *, HandleTempMemorySpace> scalar_temp_work_view_t;

  //typedef typename Kokkos::View<nonzero_value_type *, HandlePersistentMemorySpace> value_persistent_work_array_type;
  //typedef typename Kokkos::View<nnz_scalar_t *, HandlePersistentMemorySpace> nonzero_value_persistent_work_view_type;
  typedef typename Kokkos::View<nnz_scalar_t *, HandlePersistentMemorySpace> scalar_persistent_work_view_t;

  typedef typename Kokkos::View<nnz_lno_t *, HandleTempMemorySpace> nnz_lno_temp_work_view_t;
  typedef typename Kokkos::View<nnz_lno_t *, HandlePersistentMemorySpace> nnz_lno_persistent_work_view_t;
  typedef typename nnz_lno_persistent_work_view_t::HostMirror nnz_lno_persistent_work_host_view_t; //Host view type

private:
  GraphColoringHandleType *gcHandle;
  GaussSeidelHandleType *gsHandle;
  SPGEMMHandleType *spgemmHandle;
  //idx_array_type row_map;
  //idx_edge_array_type entries;
  //value_array_type values;

public:



  KokkosKernelsHandle():gcHandle(NULL), gsHandle(NULL),spgemmHandle(NULL){}
  ~KokkosKernelsHandle(){

    this->destroy_gs_handle();
    this->destroy_graph_coloring_handle();
    this->destroy_spgemm_handle();
  }

  SPGEMMHandleType *get_spgemm_handle(){
    return this->spgemmHandle;
  }

  void create_spgemm_handle(Graph::SPGEMMAlgorithm spgemm_algo = Graph::SPGEMM_DEFAULT){
    this->destroy_spgemm_handle();
    this->spgemmHandle = new SPGEMMHandleType(spgemm_algo);

  }
  void destroy_spgemm_handle(){
    if (this->spgemmHandle != NULL){
      delete this->spgemmHandle;
      this->spgemmHandle = NULL;
    }
  }

  GraphColoringHandleType *get_graph_coloring_handle(){
    return this->gcHandle;
  }
  void create_graph_coloring_handle(Graph::ColoringAlgorithm coloring_type = Graph::COLORING_DEFAULT){
    this->destroy_graph_coloring_handle();
    this->gcHandle = new GraphColoringHandleType();
    this->gcHandle->set_algorithm(coloring_type, true);
  }
  void destroy_graph_coloring_handle(){
    if (this->gcHandle != NULL){
      delete this->gcHandle;
      this->gcHandle = NULL;
    }
  }


  GaussSeidelHandleType *get_gs_handle(){
    return this->gsHandle;
  }
  void create_gs_handle(
    Graph::GSAlgorithm gs_algorithm = Graph::GS_DEFAULT){
    this->destroy_gs_handle();
    this->gsHandle = new GaussSeidelHandleType(gs_algorithm);
  }
  void destroy_gs_handle(){
    if (this->gsHandle != NULL){
      if (this->gsHandle->is_owner_of_coloring()){
        this->destroy_graph_coloring_handle();
      }
      delete this->gsHandle;
      this->gsHandle = NULL;
    }
  }


  //idx_array_type get_row_map(){return this->row_map;}
  //idx get_num_rows(){return this->row_map.dimension_0() - 1;}
  //idx get_num_nonzeroes(){return this->entries.dimension_0();}

  //idx_edge_array_type get_entries(){return this->entries;}
  //value_array_type get_values(){return this->values;}
  //void set_row_map(const idx_array_type &rm){this->row_map = rm;}
  //void set_entries(const idx_edge_array_type &e){this->entries = e;}
  //void set_values(const value_array_type &v){this->values = v;}



};

}
}

#endif //_KOKKOSKERNELHANDLE_HPP
