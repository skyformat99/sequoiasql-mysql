/* Copyright (c) 2018, SequoiaDB and/or its affiliates. All rights reserved.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; version 2 of the License.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA */

#ifndef SDB_IDX__H
#define SDB_IDX__H

#include "sql_class.h"
#include "client.hpp"
#include "sdb_cl_ptr.h"

int sdb_create_index( const KEY *keyInfo, sdb_cl_auto_ptr cl ) ;

int sdb_drop_index( const KEY *keyInfo, sdb_cl_auto_ptr cl ) ;

const char *sdb_get_idx_name( KEY *key_info ) ;

int sdb_get_idx_order( KEY * key_info, bson::BSONObj &order, int order_direction) ;

int build_match_obj_by_start_stop_key( uint keynr,
                                       const uchar *key_ptr,
                                       key_part_map keypart_map,
                                       enum ha_rkey_function find_flag,
                                       key_range *end_range,
                                       TABLE *table,
                                       bson::BSONObj &matchObj,
                                       int *order_direction) ;

#endif
