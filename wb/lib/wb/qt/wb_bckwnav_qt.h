/** 
 * Proview   Open Source Process Control.
 * Copyright (C) 2005-2017 SSAB EMEA AB.
 *
 * This file is part of Proview.
 *
 * This program is free software; you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, either version 2 of 
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with Proview. If not, see <http://www.gnu.org/licenses/>
 *
 * Linking Proview statically or dynamically with other modules is
 * making a combined work based on Proview. Thus, the terms and 
 * conditions of the GNU General Public License cover the whole 
 * combination.
 *
 * In addition, as a special exception, the copyright holders of
 * Proview give you permission to, from the build function in the
 * Proview Configurator, combine Proview with modules generated by the
 * Proview PLC Editor to a PLC program, regardless of the license
 * terms of these modules. You may copy and distribute the resulting
 * combined work under the terms of your choice, provided that every 
 * copy of the combined work is accompanied by a complete copy of 
 * the source code of Proview (the version used to produce the 
 * combined work), being distributed under the terms of the GNU 
 * General Public License plus this exception.
 **/

#ifndef wb_bckwnav_qt_h
#define wb_bckwnav_qt_h

/* wb_bckwnav_qt.h -- Backup display window */

#ifndef wb_bckwnav_h
# include "wb_bckwnav.h"
#endif

class WbBckWNavQt : public WbBckWNav {
public:
  WbBckWNavQt(void *bckw_parent_ctx, QWidget *bckw_parent_wid,
              ldh_tSession bckw_ldhses, wb_bck_list *l_list, int l_editmode,
              QWidget **w);
  ~WbBckWNavQt();

  QWidget *brow_widget;
  QWidget *form_widget;

  void set_input_focus();
};

#endif