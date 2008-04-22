/* -*- Mode: C; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*- */
/*
  Gpredict: Real-time satellite tracking and orbit prediction program

  Copyright (C)  2001-2007  Alexandru Csete, OZ9AEC.

  Authors: Alexandru Csete <oz9aec@gmail.com>

  Comments, questions and bugreports should be submitted via
  http://sourceforge.net/projects/groundstation/
  More details can be found at the project home page:

  http://groundstation.sourceforge.net/
 
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program; if not, visit http://www.fsf.org/
*/
#ifndef __GTK_ROT_CTRL_H__
#define __GTK_ROT_CTRL_H__ 1

#include <glib.h>
#include <glib/gi18n.h>
#include <gtk/gtk.h>


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */




#define GTK_TYPE_ROT_CTRL          (gtk_rot_ctrl_get_type ())
#define GTK_ROT_CTRL(obj)          GTK_CHECK_CAST (obj,\
				                       gtk_rot_ctrl_get_type (),\
						               GtkRotCtrl)

#define GTK_ROT_CTRL_CLASS(klass)  GTK_CHECK_CLASS_CAST (klass,\
							 gtk_rot_ctrl_get_type (),\
							 GtkRotCtrlClass)

#define IS_GTK_ROT_CTRL(obj)       GTK_CHECK_TYPE (obj, gtk_rot_ctrl_get_type ())


typedef struct _gtk_rot_ctrl      GtkRotCtrl;
typedef struct _GtkRotCtrlClass   GtkRotCtrlClass;



struct _gtk_rot_ctrl
{
	GtkVBox vbox;
    
    GtkWidget *digits[7];   /*!< Labels for the digits */
    GtkWidget *buttons[10]; /*!< Buttons; 0..4 up; 5..9 down */
	
    gfloat min;
    gfloat max;
    gfloat value;
};

struct _GtkRotCtrlClass
{
	GtkVBoxClass parent_class;
};



GtkType    gtk_rot_ctrl_get_type  (void);
GtkWidget* gtk_rot_ctrl_new       (gfloat min, gfloat max, gfloat val);
void       gtk_rot_ctrl_set_value (GtkRotCtrl *ctrl, gfloat val);
gfloat     gtk_rot_ctrl_get_value (GtkRotCtrl *ctrl);




#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __GTK_ROT_CTRL_H__ */
