/* ATK -  Accessibility Toolkit
 * Copyright 2014 SUSE LLC.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#ifndef __ATK_TABLE_CELL_H__
#define __ATK_TABLE_CELL_H__

#include <atk/atkobject.h>

G_BEGIN_DECLS

/*
 * AtkTableCell gives access to the cells of a two-dimentional table.
 */


#define ATK_TYPE_TABLE_CELL                    (atk_table_cell_get_type ())
#define ATK_IS_TABLE_CELL(obj)                 G_TYPE_CHECK_INSTANCE_TYPE ((obj), ATK_TYPE_TABLE_CELL)
#define ATK_TABLE_CELL(obj)                    G_TYPE_CHECK_INSTANCE_CAST ((obj), ATK_TYPE_TABLE_CELL, AtkTableCell)
#define ATK_TABLE_CELL_GET_IFACE(obj)          (G_TYPE_INSTANCE_GET_INTERFACE ((obj), ATK_TYPE_TABLE_CELL, AtkTableCellIface))

#ifndef _TYPEDEF_ATK_TABLE_CELL_
#define _TYPEDEF_ATK_TABLE_CELL_
typedef struct _AtkTableCell AtkTableCell;
#endif
typedef struct _AtkTableCellIface AtkTableCellIface;

struct _AtkTableCellIface
{
  GTypeInterface parent;

  gint        (*get_column_span)       (AtkTableCell *cell);
  GPtrArray * (*get_column_header_cells) (AtkTableCell *cell);
  gboolean        (*get_position)            (AtkTableCell *cell,
                                              gint         *row,
                                              gint         *column);
  gint        (*get_row_span)          (AtkTableCell *cell);
GPtrArray *   (*get_row_header_cells)    (AtkTableCell *cell);
  gboolean    (*get_row_column_span)  (AtkTableCell *cell,
                                          gint         *row,
                                          gint         *column,
                                          gint         *row_span,
                                          gint         *column_span);
  AtkObject * (*get_table)               (AtkTableCell *cell);
};

GType atk_table_cell_get_type (void);

gint        atk_table_cell_get_column_span       (AtkTableCell *cell);
GPtrArray * atk_table_cell_get_column_header_cells (AtkTableCell *cell);
gboolean     atk_table_cell_get_position           (AtkTableCell *cell,
                                                    gint         *row,
                                                    gint         *column);
gint        atk_table_cell_get_row_span          (AtkTableCell *cell);
GPtrArray * atk_table_cell_get_row_header_cells    (AtkTableCell *cell);
gboolean    atk_table_cell_get_row_column_span  (AtkTableCell *cell,
                                                    gint         *row,
                                                    gint         *column,
                                                    gint         *row_span,
                                                    gint         *column_span);
AtkObject * atk_table_cell_get_table               (AtkTableCell *cell);

G_END_DECLS

#endif /* __ATK_TABLE_CELL_H__ */
