/*
 * ProviewR   Open Source Process Control.
 * Copyright (C) 2005-2018 SSAB EMEA AB.
 *
 * This file is part of ProviewR.
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
 * along with ProviewR. If not, see <http://www.gnu.org/licenses/>
 *
 * Linking ProviewR statically or dynamically with other modules is
 * making a combined work based on ProviewR. Thus, the terms and
 * conditions of the GNU General Public License cover the whole
 * combination.
 *
 * In addition, as a special exception, the copyright holders of
 * ProviewR give you permission to, from the build function in the
 * ProviewR Configurator, combine ProviewR with modules generated by the
 * ProviewR PLC Editor to a PLC program, regardless of the license
 * terms of these modules. You may copy and distribute the resulting
 * combined work under the terms of your choice, provided that every
 * copy of the combined work is accompanied by a complete copy of
 * the source code of ProviewR (the version used to produce the
 * combined work), being distributed under the terms of the GNU
 * General Public License plus this exception.
 */

#ifndef xtt_stream_qt_h
#define xtt_stream_qt_h

#include "xtt_stream.h"

#include "cow_wow_qt.h"

#include <QLabel>
#include <QMouseEvent>
#include <QResizeEvent>
#include <QToolBar>
#include <QWheelEvent>

#include <phonon/VideoPlayer>
#include <phonon/VideoWidget>

class XttStreamQtWidget;

class XttStreamQt : public XttStream {
public:
  Phonon::VideoPlayer* playbin2; /* Our one and only pipeline */
  Phonon::State state; /* Current state of the pipeline */
  pwr_tTime mb_press_time;
  int mb_press_x;
  int mb_press_y;
  int scroll_x;
  int scroll_y;
  int scroll_direction;
  int scroll_cnt;
  int popupmenu_x;
  int popupmenu_y;
  int ptz_box_displayed;
  int is_live;
  pwr_tTime buftime;

  QSlider* slider; /* Slider widget to keep track of current position */
  Phonon::VideoWidget* video_form;
  QWidget* main_box;
  QWidget* ptz_box;
  QLabel* ptz_pan;
  QLabel* ptz_tilt;
  QLabel* ptz_zoom;
  QToolBar* tools;

  void* overlay;
  CoWowTimer* reconnect_timerid;
  int no_uri;

  XttStreamQt(QWidget* parent_wid, void* parent_ctx, const char* name,
      const char* uri, int width, int height, int x, int y, double scan_time,
      unsigned int options, int embedded, pwr_tAttrRef* arp, pwr_tStatus* sts);
  ~XttStreamQt();

  void pop();
  void set_size(int width, int height);
  void setup();

  void* get_widget()
  {
    return main_box;
  }

  void create_popup_menu(int x, int y);
  void erase_window();

  static void scroll_cb(void* data);
  static void reconnect(void* data);

  void togglePtzBoxVisible();

private:
  QAction* addToolItemSpecial(QToolBar* tools, const char* objName,
      const char* tooltip, const char* callback, const char* iconName);

  XttStreamQtWidget* toplevel;
};

class XttStreamQtWidget : public QWidget {
  Q_OBJECT

public:
  XttStreamQtWidget(XttStreamQt* parent_ctx, QWidget* parent)
      : QWidget(parent), stream(parent_ctx)
  {
  }

protected:
  void closeEvent(QCloseEvent* event);
  void resizeEvent(QResizeEvent* event);
  void mousePressEvent(QMouseEvent* event);
  void mouseReleaseEvent(QMouseEvent* event);
  void wheelEvent(QWheelEvent* event);

public slots:
  void slider_cb(int value);
  void error_cb(Phonon::ErrorType error);
  void state_changed_cb(Phonon::State new_state);

  void activate_zoomreset();
  void activate_zoomin();
  void activate_zoomout();

  void activate_scroll_left();
  void activate_scroll_right();
  void activate_page_left();
  void activate_page_right();
  void activate_scroll_down();
  void activate_scroll_up();
  void activate_page_down();
  void activate_page_up();
  void activate_preset_position();
  void activate_preset_store_pos();
  void activate_get_position();

private:
  void zoom_helper(int value);
  void pan_helper(int value);
  void tilt_helper(int value);

  XttStreamQt* stream;
};

#endif