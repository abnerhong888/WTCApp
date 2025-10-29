# GTK4.0 Widgets Category


# 1. Basic Display Widgets
| Widget             | Description                                                         |
| ------------------ | ------------------------------------------------------------------- |
| **GtkLabel**       | Displays a line (or multiple lines) of text.                        |
| **GtkImage**       | Shows an image from a file, icon, or pixbuf.                        |
| **GtkProgressBar** | Visual progress indicator (can be horizontal/vertical).             |
| **GtkSpinner**     | Animated “loading” spinner.                                         |
| **GtkSeparator**   | Horizontal or vertical line for dividing areas.                     |
| **GtkLevelBar**    | Displays a level (e.g., volume or battery strength).                |
| **GtkPicture**     | Displays an image (newer replacement for `GtkImage` in some cases). |

# 2. Input / Interaction Widgets
| Widget                            | Description                                        |
| ------------------------          | -------------------------------------------------- |
| **GtkButton**                     | Standard clickable button.                         |
| **GtkToggleButton**               | A button that can stay pressed (“on/off”).         |
| **GtkCheckButton**                | Checkbox-style toggle.                             |
| **GtkSwitch**                     | Modern toggle switch (on/off).                     |
| **GtkRadioButton (gtk3.0)**       | Radio button — part of a mutually exclusive group. | 
| **GtkLinkButton**                 | Button that opens a hyperlink.                     |
| **GtkEntry**                      | Single-line text input.                            |
| **GtkPasswordEntry**              | Entry that hides the text input (for passwords).   |
| **GtkSearchEntry**                | Entry optimized for search bars.                   |
| **GtkSpinButton**                 | Entry with up/down arrows for numeric input.       |
| **GtkScale**                      | Slider control for selecting a numeric value.      |
| **GtkColorButton (gtk3.0)**       | Button that opens a color picker.                  |
| **GtkFontButton (gtk3.0)**        | Button that opens a font selection dialog.         |
| **GtkFileChooserButton (gtk3.0)** | Button that opens a file picker dialog.            |

# 3. Text and Data Display Widgets
| Widget                            | Description                                             |
| ----------------------            | ------------------------------------------------------- |
| **GtkTextView**                   | Multi-line editable or read-only text area.             |
| **GtkTreeView (gtk3.0)**          | Displays data in tree or table form.                    |
| **GtkListView**                   | Modern replacement for list displays (GTK 4).           |
| **GtkColumnView**                 | Modern table-like view (replacement for `GtkTreeView`). |
| **GtkEntryCompletion (gtk3.0)**   | Provides autocomplete for a `GtkEntry`.                 |

# 4. Containers / Layout Widgets
| Widget                | Description                                            |
| --------------------- | ------------------------------------------------------ |
| **GtkBox**            | Linear layout (horizontal/vertical).                   |
| **GtkGrid**           | Grid layout (rows/columns).                            |
| **GtkStack**          | Stack multiple children, showing one at a time.        |
| **GtkOverlay**        | Layer widgets on top of each other.                    |
| **GtkPaned**          | Split view (resizable divider).                        |
| **GtkRevealer**       | Animated show/hide for a single child.                 |
| **GtkExpander**       | Expand/collapse a section.                             |
| **GtkFixed**          | Absolute positioning (non-responsive).                 |
| **GtkFlowBox**        | Dynamically flowing list of widgets (like tag clouds). |
| **GtkListBox**        | Vertical list of selectable rows.                      |
| **GtkNotebook**       | Tabbed interface (multiple pages).                     |
| **GtkScrolledWindow** | Adds scrollbars to a child widget.                     |
| **GtkFrame**          | Adds a border and optional label around a child.       |
| **GtkHeaderBar**      | Modern titlebar for windows (can hold buttons).        |

# 5. Window and Top-Level Widgets
| Widget                            | Description                                  |
| -----------------------           | -------------------------------------------- |
| **GtkWindow**                     | Main application window.                     |
| **GtkDialog (gtk3.0)**            | Standard dialog window.                      |
| **GtkMessageDialog (gtk3.0)**     | Simple message popup (info, warning, error). |
| **GtkAboutDialog**                | Pre-built “About” dialog.                    |
| **GtkPopover**                    | Floating popup anchored to a widget.         |
| **GtkMenuButton**                 | Button that opens a popover menu.            |
| **GtkAppChooserDialog (gtk3.0)**  | Dialog to pick an app to open a file.        |

# 6. Menus and Selectors
| Widget              | Description                          |
| ------------------- | ------------------------------------ |
| **GtkComboBoxText** | Dropdown with text entries.          |
| **GtkDropDown**     | New GTK 4 replacement for ComboBox.  |
| **GtkMenuButton**   | Button that opens a menu or popover. |
| **GtkPopoverMenu**  | Menu inside a popover window.        |

# 7. Visual / Utility Widgets
| Widget                                                    | Description                                |
| --------------------------------------------------------- | ------------------------------------------ |
| **GtkDrawingArea**                                        | Area for custom drawing (e.g. with Cairo). |
| **GtkGLArea**                                             | Area for OpenGL rendering.                 |
| **GtkPicture**                                            | Show images with modern rendering.         |
| **GtkGestureClick / GtkGestureDrag / GtkEventController** | Handle user gestures and events.           |

# 8. Specialized / Modern Widgets (GTK 4+)
| Widget                 | Description                                             |
| ---------------------- | ------------------------------------------------------- |
| **GtkOverlay**         | Stack overlays on top of content.                       |
| **GtkStackSwitcher**   | Linked control to switch visible child of a `GtkStack`. |
| **GtkShortcutsWindow** | Displays keyboard shortcuts in a nice overlay.          |
| **GtkStatusbar**       | Status bar (older, replaced by custom layouts).         |
| **GtkActionBar**       | Horizontal bar for buttons at the bottom.               |


# ???
| **GtkTextBuffer**      | Backing storage for a `GtkTextView`.                    |