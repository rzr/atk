/* ATK -  Accessibility Toolkit
 * Copyright 2001 Sun Microsystems Inc.
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

#ifndef __ATK_OBJECT_H__
#define __ATK_OBJECT_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <glib-object.h>

/*
 * AtkObject represents the minimum information all accessible objects
 * return. This information includes accessible name, accessible
 * description, role and state of the object, as well information about
 * its parent and children. It is also possible to obtain more specific
 * accessibility information about a component if it supports one or more
 * of the following interfaces:
 */

typedef enum
{
  ATK_ROLE_INVALID,
  /* A label which represents an accelerator */
  ATK_ROLE_ACCEL_LABEL,
  /* An object is used to alert the user about something */
  ATK_ROLE_ALERT,
  /* An object which is an animated image */
  ATK_ROLE_ANIMATION,
  /* An arrow in one of the four cardinal directoions */
  ATK_ROLE_ARROW,
  /* An object that displays a calendar and allows the user to select a date */
  ATK_ROLE_CALENDAR,
  /* An object that can be drawn into and is used to trap events */
  ATK_ROLE_CANVAS,
  /*
   * A choice that can be checked or unchecked and provides a separate
   * indicator for the current state.
   */
  ATK_ROLE_CHECK_BOX,
  /* A menu item with a check box */
  ATK_ROLE_CHECK_MENU_ITEM,
  /* A specialized dialog that lets the user choose a color. */
  ATK_ROLE_COLOR_CHOOSER,
  /* The header for a column of data */
  ATK_ROLE_COLUMN_HEADER,
  /* A list of choices the user can select from */
  ATK_ROLE_COMBO_BOX,
  /* An object whose purpose is to allow a user to edit a date */
  ATK_ROLE_DATE_EDITOR,
  /* An inconifed internal frame within a DESKTOP_PANE */
  ATK_ROLE_DESKTOP_ICON,
  /*
   * A pane that supports internal frames and iconified versions of those
   * internal frames.
   */
  ATK_ROLE_DESKTOP_FRAME,
  /* An object whose purpose is to allow a user to set a value */
  ATK_ROLE_DIAL,
  /* A top level window with title bar and a border */
  ATK_ROLE_DIALOG,
  /*
   * A pane that allows the user to navigate through and select the contents
   * of a directory
   */
  ATK_ROLE_DIRECTORY_PANE,
  /*
   * A specialized dialog that displays the files in the directory and lets
   * the user select a file, browse a different directory, or specify a
   * filename.
   */
  /* An object used for drawing custom user interface elements */
  ATK_ROLE_DRAWING_AREA,
  /* A specialized dialog that lets the user choose a file. */
  ATK_ROLE_FILE_CHOOSER,
  /* A object that fills up space in a user interface */
  ATK_ROLE_FILLER,
  /* A specialized dialog that lets the user choose a font. */
  ATK_ROLE_FONT_CHOOSER,
  /* A top level window with a title bar, border, menubar, etc. */
  ATK_ROLE_FRAME,
  /* A pane that is guaranteed to be painted on top of all panes beneath it */
  ATK_ROLE_GLASS_PANE,
  /*
   * A document container for HTML, whose children
   * represent the document content.
   */
  ATK_ROLE_HTML_CONTAINER,
  /* A small fixed size picture, typically used to decorate components */
  ATK_ROLE_ICON,
  /* An object whose primary purpose is to display an image */
  ATK_ROLE_IMAGE,
  /* A frame-like object that is clipped by a desktop pane. */
  ATK_ROLE_INTERNAL_FRAME,
  /* An object used to present an icon or short string in an interface */
  ATK_ROLE_LABEL,
  /*
   * A specialized pane that allows its children to be drawn in layers,
   * providing a form of stacking order.
   */
  ATK_ROLE_LAYERED_PANE,
  /*
   * An object that presents a list of objects to the user and allows the
   * user to select one or more of them.
   */
  ATK_ROLE_LIST,
   /* An object that represents an element of a list. */
  ATK_ROLE_LIST_ITEM,
  /*
   * An object usually found inside a menu bar that contains a list of
   * actions the user can choose from.
   */
  ATK_ROLE_MENU,
  /*
   * An object usually drawn at the top of the primary dialog box of an
   * application that contains a list of menus the user can choose from.
   */
  ATK_ROLE_MENU_BAR,
  /*
   * An object usually contained in a menu that presents an action the
   * user can choose.
   */
  ATK_ROLE_MENU_ITEM,
  /* A specialized pane whose primary use is inside a DIALOG */
  ATK_ROLE_OPTION_PANE,
  /* An object that is a child of a page tab list */
  ATK_ROLE_PAGE_TAB,
  /*
   * An object that presents a series of panels (or page tabs), one at a time,
   * through some mechanism provided by the object.
   */
  ATK_ROLE_PAGE_TAB_LIST,
  /* A generic container that is often used to group objects. */
  ATK_ROLE_PANEL,
  /*
   * A text object uses for passwords, or other places where the text
   * content is not shown visibly to the user.
   */
  ATK_ROLE_PASSWORD_TEXT,
  /*
   * A temporary window that is usually used to offer the user a list of
   * choices, and then hides when the user selects one of those choices.
   */
  ATK_ROLE_POPUP_MENU,
  /* An object used to indicate how much of a task has been completed. */
  ATK_ROLE_PROGRESS_BAR,
  /*
   * An object the user can manipulate to tell the application to do
   * something.
   */
  ATK_ROLE_PUSH_BUTTON,
  /*
   * A specialized check box that will cause other radio buttons in the
   * same group to become uncghecked when this one is checked.
   */
  ATK_ROLE_RADIO_BUTTON,
  /* 
   * A check menu item which belongs to a group. At each instant exactly 
   * one of the radio menu items from a group is selected
   */
  ATK_ROLE_RADIO_MENU_ITEM,
  /*
   * A specialized pane that has a glass pane and a layered pane as its
   * children.
   */
  ATK_ROLE_ROOT_PANE,
  /* The header for a row of data */
  ATK_ROLE_ROW_HEADER,
  /*
   * An object usually used to allow a user to incrementally view a large
   * amount of data.
   */
  ATK_ROLE_SCROLL_BAR,
  /*
   * An object that allows a user to incrementally view a large amount
   * of information.
   */
  ATK_ROLE_SCROLL_PANE,
  /*
   * An object usually contained in a menu to provide a visible and
   * logical separation of the contents in a menu.
   */
  ATK_ROLE_SEPARATOR,
  /* An object that allows the user to select from a bounded range */
  ATK_ROLE_SLIDER,
  /* A specialized panel that presents two other panels at the same time. */
  ATK_ROLE_SPLIT_PANE,
  /* An object used to get an integer or floating point number from the user */
  ATK_ROLE_SPIN_BUTTON,
  /* An object which reports messages of minor importance to the user */
  ATK_STATUS_BAR,
  /* An object used to rpesent information in terms of rows and columns. */
  ATK_ROLE_TABLE,
  ATK_ROLE_TABLE_CELL,
  ATK_ROLE_TABLE_COLUMN_HEADER,
  ATK_ROLE_TABLE_ROW_HEADER,
  /* A menu item used to tear off and reattach its menu */
  ATK_ROLE_TEAR_OFF_MENU_ITEM,
  /* An object that presents text to the user */
  ATK_ROLE_TEXT,
  /*
   * A specialized push button that can be checked or unchecked, but does
   * not procide a separate indicator for the current state.
   */
  ATK_ROLE_TOGGLE_BUTTON,
  /*
   * A bar or palette usually composed of push buttons or toggle buttons
   */
  ATK_ROLE_TOOL_BAR,
  /*
   * An object that provides information about another object
   */
  ATK_ROLE_TOOL_TIP,
  /* An object used to repsent hierarchical information to the user. */
  ATK_ROLE_TREE,
  /*
   * The object contains some Accessible information, but its role is
   * not known.
   */
  ATK_ROLE_UNKNOWN,
  /* An object usually used in a scroll pane. */
  ATK_ROLE_VIEWPORT,
  /* A top level window with no title or border */
  ATK_ROLE_WINDOW,
  /* not a valid role, used for finding end of enumeration. */
  ATK_ROLE_LAST_DEFINED
} AtkRole;

AtkRole                  atk_role_register        (const gchar *name);


#define ATK_TYPE_OBJECT                           (atk_object_get_type ())
#define ATK_OBJECT(obj)                           (G_TYPE_CHECK_INSTANCE_CAST ((obj), ATK_TYPE_OBJECT, AtkObject))
#define ATK_OBJECT_CLASS(klass)                   (G_TYPE_CHECK_CLASS_CAST ((klass), ATK_TYPE_OBJECT, AtkObjectClass))
#define ATK_IS_OBJECT(obj)                        (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ATK_TYPE_OBJECT))
#define ATK_IS_OBJECT_CLASS(klass)                (G_TYPE_CHECK_CLASS_TYPE ((klass), ATK_TYPE_OBJECT))
#define ATK_OBJECT_GET_CLASS(obj)                 (G_TYPE_INSTANCE_GET_CLASS ((obj), ATK_TYPE_OBJECT, AtkObjectClass))

#define ATK_TYPE_IMPLEMENTOR                      (atk_implementor_get_type ())
#define ATK_IS_IMPLEMENTOR(obj)                   G_TYPE_CHECK_INSTANCE_TYPE ((obj), ATK_TYPE_IMPLEMENTOR)
#define ATK_IMPLEMENTOR(obj)                      G_TYPE_CHECK_INSTANCE_CAST ((obj), ATK_TYPE_IMPLEMENTOR, AtkImplementor)
#define ATK_IMPLEMENTOR_GET_IFACE(obj)            (G_TYPE_INSTANCE_GET_INTERFACE ((obj), ATK_TYPE_IMPLEMENTOR, AtkImplementorIface))


typedef struct _AtkImplementor            AtkImplementor; /* dummy typedef */
typedef struct _AtkImplementorIface       AtkImplementorIface;


typedef struct _AtkObject                 AtkObject;
typedef struct _AtkObjectClass            AtkObjectClass;
typedef struct _AtkRelationSet            AtkRelationSet;
typedef struct _AtkStateSet               AtkStateSet;

struct _AtkPropertyValues
{
  gchar  *property_name;
  GValue old_value;
  GValue new_value;
};

typedef struct _AtkPropertyValues        AtkPropertyValues;

/*
 * For most properties the old_value field of AtkPropertyValues will
 * not contain a valid value.
 *
 * Currently, the only property for which old_value is used is
 * accessible-state; for instance if there is a focus state the
 * property change handler will be called for the object which lost the focus
 * with the old_value containing an AtkState value corresponding to focused
 * and the property change handler will be called for the object which
 * received the focus with the new_value containing an AtkState value
 * corresponding to focused.
 */
typedef void (*AtkPropertyChangeHandler) (AtkObject*, AtkPropertyValues*);


struct _AtkObject
{
  GObject parent;

  gchar *description;
  gchar *name;
  AtkObject *accessible_parent;
  AtkRole role;
  AtkRelationSet *relation_set;
};

struct _AtkObjectClass
{
  GObjectClass parent;

  /*
   * Gets the accessible name of the object
   */
  G_CONST_RETURN gchar*    (* get_name)            (AtkObject                *accessible);
  /*
   * Gets the accessible description of the object
   */
  G_CONST_RETURN gchar*    (* get_description)     (AtkObject                *accessible);
  /*
   * Gets the accessible parent of the object
   */
  AtkObject*               (*get_parent)           (AtkObject                *accessible);

  /*
   * Gets the number of accessible children of the object
   */
  gint                    (* get_n_children)       (AtkObject                *accessible);
  /*
   * Returns a reference to the specified accessible child of the object.
   * The accessible children are 0-based so the first accessible child is
   * at index 0, the second at index 1 and so on.
   */
  AtkObject*              (* ref_child)            (AtkObject                *accessible,
                                                    gint                      i);
  /*
   * Gets the 0-based index of this object in its parent; returns -1 if the
   * object does not have an accessible parent.
   */
  gint                    (* get_index_in_parent) (AtkObject                 *accessible);
  /*
   * Gets the RelationSet associated with the object
   */
  AtkRelationSet*         (* ref_relation_set)    (AtkObject                 *accessible);
  /*
   * Gets the role of the object
   */
  AtkRole                 (* get_role)            (AtkObject                 *accessible);
  /*
   * Gets the state set of the object
   */
  AtkStateSet*            (* ref_state_set)       (AtkObject                 *accessible);
  /*
   * Sets the accessible name of the object
   */
  void                    (* set_name)            (AtkObject                 *accessible,
                                                   const gchar               *name);
  /*
   * Sets the accessible description of the object
   */
  void                    (* set_description)     (AtkObject                 *accessible,
                                                   const gchar               *description);
  /*
   * Sets the accessible parent of the object
   */
  void                    (* set_parent)          (AtkObject                 *accessible,
                                                   AtkObject                 *parent);
  /*
   * Sets the accessible role of the object
   */
  void                    (* set_role)            (AtkObject                 *accessible,
                                                   AtkRole                   role);
  /*
   * Specifies a function to be called when a property changes value
   */
guint                     (* connect_property_change_handler)    (AtkObject
                 *accessible,
                                                                  AtkPropertyChangeHandler       *handler);
  /*
   * Removes a property change handler which was specified using
   * connect_property_change_handler
   */
void                      (* remove_property_change_handler)     (AtkObject
                *accessible,
                                                                  guint
                handler_id);
  /*
   * The signal handler which is executed when there is a change in the
   * children of the object
   */
  void                    (* children_changed)    (AtkObject                  *accessible,
                                                   gint                       change_index,
                                                   AtkObject                  *changed_child);
  /*
   * The signal handler which is executed  when there is a focus event
   * for an object.
   */
  void                    (*focus_event)          (AtkObject                  *accessible,
                                                   gboolean                   focus_in);
};

GType            atk_object_get_type   (void);

struct _AtkImplementorIface
{
  GTypeInterface parent;

  AtkObject*   (*ref_accessible) (AtkImplementor *implementor);
};
GType atk_implementor_get_type (void);

/*
 * This method uses the ref_accessible method in AtkImplementorIface,
 * if the object's class implements AtkImplementorIface.
 * Otherwise it returns %NULL.
 *
 * IMPORTANT:
 * Note also that because this method may return flyweight objects,
 * it increments the returned AtkObject's reference count.
 * Therefore it is the responsibility of the calling
 * program to unreference the object when no longer needed.
 * (c.f. gtk_widget_get_accessible() where this is not the case).
 */
AtkObject*              atk_implementor_ref_accessible            (AtkImplementor *implementor);

/*
 * Properties directly supported by AtkObject
 */

G_CONST_RETURN gchar*   atk_object_get_name                       (AtkObject *accessible);
G_CONST_RETURN gchar*   atk_object_get_description                (AtkObject *accessible);
AtkObject*              atk_object_get_parent                     (AtkObject *accessible);
gint                    atk_object_get_n_accessible_children      (AtkObject *accessible);
AtkObject*              atk_object_ref_accessible_child           (AtkObject *accessible,
                                                                   gint        i);
AtkRelationSet*         atk_object_ref_relation_set               (AtkObject *accessible);
AtkRole                 atk_object_get_role                       (AtkObject *accessible);
AtkStateSet*            atk_object_ref_state_set                  (AtkObject *accessible);
gint                    atk_object_get_index_in_parent            (AtkObject *accessible);
void                    atk_object_set_name                       (AtkObject *accessible,
                                                                   const gchar *name);
void                    atk_object_set_description                (AtkObject *accessible,
                                                                   const gchar *description);
void                    atk_object_set_parent                     (AtkObject *accessible,
                                                                   AtkObject *parent);
void                    atk_object_set_role                       (AtkObject *accessible,
                                                                   AtkRole   role);


/*
 * to install property change listener, one must
 * install signal handler for gobject "properties_changed" signal.
 * (for single notifications of multiple changes).
 * We could use the "notify" signal instead.
 *
 */
guint                atk_object_connect_property_change_handler  (AtkObject                      *accessible,
                                                                  AtkPropertyChangeHandler       *handler);
void                 atk_object_remove_property_change_handler  (AtkObject                      *accessible,
                                                                  guint                         handler_id);

/*
 * Note: the properties which are registered with the GType
 *   property registry, for type ATK_TYPE_OBJECT, are as follows:
 *
 *   "accessible-name"
 *   "accessible-description"
 *   "accessible-parent"
 *   "accessible-child"
 *   "accessible-role"
 *   "accessible-state"
 *
 * accessibility property change listeners should use the
 *   normal GObject property interfaces and "properties_changed"
 *   signal handler semantics to interpret the property change
 *   information relayed from AtkObject.
 *   (AtkObject instances will connect to the "properties_changed"
 *   signal in their host objects, and relay the signals when appropriate).
 */

/* For other signals, see related interfaces
 *
 *    AtkActionIface,
 *    AtkComponentIface,
 *    AtkHypertextIface,
 *    AtkImageIface,
 *    AtkSelectionIface,
 *    AtkTableIface,
 *    AtkTextIface,
 *    AtkValueIface.
 *
 *  The usage model for obtaining these interface instances is:
 *    ATK_<interfacename>_GET_IFACE(GObject *accessible),
 *    where accessible, though specified as a GObject, is
 *    the AtkObject instance being queried.
 *  More usually, the interface will be used via a cast to the
 *    interface's corresponding "type":
 *
 *    AtkText textImpl = ATK_TEXT(accessible);
 *    if (textImpl)
 *      {
 *        cpos = atk_text_get_caret_position(textImpl);
 *      }
 *
 *  If it's known in advance that accessible implements AtkTextIface,
 *    this is shortened to:
 *
 *    cpos = atk_text_get_caret_position (ATK_TEXT (accessible));
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* __ATK_OBJECT_H__ */