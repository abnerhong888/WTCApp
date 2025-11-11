#ifndef __gtkaaIWidget_H__
#define __gtkaaIWidget_H__

#include "gtk/gtk.h"
#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IWidget: public IEvent{
public:
    gtkaa::sptrGTKWidget m_widget = nullptr;
    std::string m_widget_name = "";
public:
    virtual ~IWidget() = default;
    IWidget() = default;
    IWidget(std::string widgetName){
        m_widget_name = widgetName;
    }
    IWidget(GtkWidget* widget, std::string widgetName = ""){
        m_widget_name = widgetName;
        createWidget(widget);
    }
    IWidget(gtkaa::sptrGTKWidget widget, std::string widgetName = ""){
        m_widget_name = widgetName;
        m_widget = widget;
    }
    IWidget(IWidget& widget){
        m_widget = widget.m_widget;
        m_widget_name = widget.m_widget_name;
    }
    IWidget(const IWidget& widget){
        m_widget = widget.m_widget;
        m_widget_name = widget.m_widget_name;
    }
    virtual gtkaa::sptrGTKWidget  createWidget(GtkWidget* widget){
        if(!m_widget_name.empty())
            gtk_widget_set_name(widget, m_widget_name.c_str());

        if(!m_widget) 
            m_widget = gtkaa::make_ptr_release(widget);

        return m_widget;
    }
    virtual gpointer get() { 
        return m_widget.get(); 
    }

    template<typename T>
    void operator=(T& widget){
        m_widget = widget.m_widget;
        m_widget_name = widget.m_widget_name;
    }

    virtual void unparent(){
        gtk_widget_unparent(GTK_WIDGET(get()));
    }
    virtual void map(){
        gtk_widget_map(GTK_WIDGET(get()));
    }
    virtual void unmap(){
        gtk_widget_unmap(GTK_WIDGET(get()));
    }
    virtual void realize(){
        gtk_widget_realize(GTK_WIDGET(get()));
    }
    virtual void unrealize(){
        gtk_widget_unrealize(GTK_WIDGET(get()));
    }
    virtual void queue_draw(){
        gtk_widget_queue_draw(GTK_WIDGET(get()));
    }
    virtual void queue_resize(){
        gtk_widget_queue_resize(GTK_WIDGET(get()));
    }
    virtual void queue_allocate(){
        gtk_widget_queue_allocate(GTK_WIDGET(get()));
    }
    virtual GdkFrameClock* get_frame_clock(){
        return gtk_widget_get_frame_clock(GTK_WIDGET(get()));
    }
    virtual void size_allocate(GtkAllocation* allocation, int baseline){
        gtk_widget_size_allocate(GTK_WIDGET(get()), allocation, baseline);
    }
    virtual GtkSizeRequestMode get_request_mode(){
        return gtk_widget_get_request_mode(GTK_WIDGET(get()));
    }
    virtual void measure(GtkOrientation orientation, int for_size, int *minimum, int *natural, int *minimum_baseline, int *natural_baseline){
        gtk_widget_measure(GTK_WIDGET(get()), orientation, for_size, minimum, natural, minimum_baseline, natural_baseline);
    }
    virtual void get_preferred_size(GtkRequisition *minimum_size, GtkRequisition *natural_size){
        gtk_widget_get_preferred_size(GTK_WIDGET(get()), minimum_size, natural_size);
    }
    virtual void set_layout_manager(GtkLayoutManager *manager){
        gtk_widget_set_layout_manager(GTK_WIDGET(get()), manager);
    }
    virtual GtkLayoutManager* get_layout_manager(){
        return gtk_widget_get_layout_manager(GTK_WIDGET(get()));
    }
    virtual void class_set_layout_manager_type(GtkWidgetClass *widget_class, GType type){
        gtk_widget_class_set_layout_manager_type(widget_class, type);
    }
    virtual GType class_get_layout_manager_type(GtkWidgetClass *widget_class){
        return gtk_widget_class_get_layout_manager_type(widget_class);
    }
    virtual void class_add_binding(GtkWidgetClass      *widget_class,
                                           guint                keyval,
                                           GdkModifierType      mods,
                                           GtkShortcutFunc      callback,
                                           const char          *format_string,
                                           ...)
    {
        va_list args;
        va_start(args, format_string);
        gtk_widget_class_add_binding(widget_class, keyval, mods, callback, format_string, args);
        va_end(args);            
    }
    virtual void class_add_binding_signal(GtkWidgetClass      *widget_class,
                                           guint                keyval,
                                           GdkModifierType      mods,
                                           const char          *signal,
                                           const char          *format_string,
                                           ...)
    {
        va_list args;
        va_start(args, format_string);
        gtk_widget_class_add_binding_signal(widget_class, keyval, mods, signal, format_string, args);
        va_end(args);            
    }
    virtual void class_add_binding_action(GtkWidgetClass      *widget_class,
                                           guint                keyval,
                                           GdkModifierType      mods,
                                           const char          *action_name,
                                           const char          *format_string,
                                           ...)
    {
        va_list args;
        va_start(args, format_string);
        gtk_widget_class_add_binding_action(widget_class, keyval, mods, action_name, format_string, args);
        va_end(args);            
    }

    virtual void class_add_shortcut(GtkWidgetClass      *widget_class, GtkShortcut *shortcut){
        gtk_widget_class_add_shortcut(widget_class, shortcut);
    }
    virtual void class_set_activate_signal(GtkWidgetClass *widget_class, guint signal_id){
        gtk_widget_class_set_activate_signal(widget_class, signal_id);
    }
    virtual void class_set_activate_signal_from_name(GtkWidgetClass *widget_class, const char *signal_name){
        gtk_widget_class_set_activate_signal_from_name(widget_class, signal_name);
    }
    virtual guint class_get_activate_signal(GtkWidgetClass *widget_class){
        return gtk_widget_class_get_activate_signal(widget_class);
    }
    virtual gboolean mnemonic_activate(gboolean group_cycling){
        return gtk_widget_mnemonic_activate(GTK_WIDGET(this->get()), group_cycling);
    }
    virtual gboolean activate(){
        return gtk_widget_activate(GTK_WIDGET(this->get()));
    }
    virtual void set_can_focus(gboolean can_focus){
        gtk_widget_set_can_focus(GTK_WIDGET(this->get()), can_focus);
    }
    virtual gboolean get_can_focus(){
        return gtk_widget_get_can_focus(GTK_WIDGET(this->get()));
    }
    virtual void set_focusable(gboolean focusable){
        gtk_widget_set_focusable(GTK_WIDGET(this->get()), focusable);
    }
    virtual gboolean get_focusable(){
        return gtk_widget_get_focusable(GTK_WIDGET(this->get()));
    }
    virtual gboolean has_focus(){
        return gtk_widget_has_focus(GTK_WIDGET(this->get()));
    }
    virtual gboolean is_focused(){
        return gtk_widget_is_focus(GTK_WIDGET(this->get()));
    }
    virtual gboolean has_visible_focus(){
        return gtk_widget_has_visible_focus(GTK_WIDGET(this->get()));
    }
    virtual gboolean grab_focus(){
        return gtk_widget_grab_focus(GTK_WIDGET(this->get()));
    }
    virtual void set_focus_on_click(gboolean focus_on_click){
        gtk_widget_set_focus_on_click(GTK_WIDGET(this->get()), focus_on_click);
    }
    virtual gboolean get_focus_on_click(){
        return gtk_widget_get_focus_on_click(GTK_WIDGET(this->get()));
    }
    virtual void set_can_target(gboolean can_target){
        gtk_widget_set_can_target(GTK_WIDGET(this->get()), can_target);
    }
    virtual gboolean get_can_target(){
        return gtk_widget_get_can_target(GTK_WIDGET(this->get()));
    }
    virtual gboolean has_default(){
        return gtk_widget_has_default(GTK_WIDGET(this->get()));
    }
    virtual void set_receives_default(gboolean receives_default){
        gtk_widget_set_receives_default(GTK_WIDGET(this->get()), receives_default);
    }
    virtual gboolean get_receives_default(){
        return gtk_widget_get_receives_default(GTK_WIDGET(this->get()));
    }
    virtual void set_name(const char* name){
        gtk_widget_set_name(GTK_WIDGET(this->get()), name);
    }
    virtual const char* get_name(){
        return gtk_widget_get_name(GTK_WIDGET(this->get()));
    }
    virtual void set_state_flags(GtkStateFlags flags, gboolean clear){
        gtk_widget_set_state_flags(GTK_WIDGET(this->get()), flags, clear);
    }
    virtual void unset_state_flags(GtkStateFlags flags){
        gtk_widget_unset_state_flags(GTK_WIDGET(this->get()), flags);
    }
    virtual GtkStateFlags get_state_flags(){
        return gtk_widget_get_state_flags(GTK_WIDGET(this->get()));
    }
    virtual void set_sensitive(gboolean sensitive){
        gtk_widget_set_sensitive(GTK_WIDGET(this->get()), sensitive);
    }
    virtual gboolean get_sensitive(){
        return gtk_widget_get_sensitive(GTK_WIDGET(this->get()));
    }
    virtual gboolean is_sensitive(){
        return gtk_widget_is_sensitive(GTK_WIDGET(this->get()));
    }
    virtual void set_visible(gboolean visible){
        gtk_widget_set_visible(GTK_WIDGET(this->get()), visible);
    }
    virtual gboolean get_visible(){
        return gtk_widget_get_visible(GTK_WIDGET(this->get()));
    }
    virtual gboolean is_visible(){
        return gtk_widget_is_visible(GTK_WIDGET(this->get()));
    }
    virtual gboolean is_drawable(){
        return gtk_widget_is_drawable(GTK_WIDGET(this->get()));
    }
    virtual gboolean get_realized(){
        return gtk_widget_get_realized(GTK_WIDGET(this->get()));
    }
    virtual gboolean get_mapped(){
        return gtk_widget_get_mapped(GTK_WIDGET(this->get()));
    }
    virtual void set_parent(IWidget* parent){
        gtk_widget_set_parent(GTK_WIDGET(this->get()), GTK_WIDGET(parent->get()));
    }
    virtual IWidget get_parent(){
        return { gtk_widget_get_parent(GTK_WIDGET(this->get())) };
    }
    virtual GtkRoot* get_root(){
        return gtk_widget_get_root(GTK_WIDGET(this->get()));
    }
    virtual GtkNative* get_native(){
        return gtk_widget_get_native(GTK_WIDGET(this->get()));
    }
    virtual void set_child_visible(gboolean child_visible){
        gtk_widget_set_child_visible(GTK_WIDGET(this->get()), child_visible);
    }
    virtual gboolean get_child_visible(){
        return gtk_widget_get_child_visible(GTK_WIDGET(this->get()));
    }
    virtual gboolean compute_transform(IWidget* target, graphene_matrix_t *out_transform){
        return gtk_widget_compute_transform(GTK_WIDGET(this->get()), GTK_WIDGET(target->get()), out_transform);
    }
    virtual gboolean compute_bounds(IWidget* target, graphene_rect_t *out_bounds){
        return gtk_widget_compute_bounds(GTK_WIDGET(this->get()), GTK_WIDGET(target->get()), out_bounds);
    }
    virtual gboolean compute_point(IWidget* target, graphene_point_t *point, graphene_point_t *out_point){
        return gtk_widget_compute_point(GTK_WIDGET(this->get()), GTK_WIDGET(target->get()), point, out_point);
    }
    virtual int get_width(){
        return gtk_widget_get_width(GTK_WIDGET(this->get()));
    }
    virtual int get_height(){
        return gtk_widget_get_height(GTK_WIDGET(this->get()));
    }
    virtual int get_baseline(){
        return gtk_widget_get_baseline(GTK_WIDGET(this->get()));
    }
    virtual int get_size(GtkOrientation orientation){
        return gtk_widget_get_size(GTK_WIDGET(this->get()), orientation);
    }
    virtual gboolean child_focus(GtkDirectionType direction){
        return gtk_widget_child_focus(GTK_WIDGET(this->get()), direction);
    }
    virtual gboolean keynav_failed(GtkDirectionType direction){
        return gtk_widget_keynav_failed(GTK_WIDGET(this->get()), direction);
    }
    virtual void error_bell(){
        gtk_widget_error_bell(GTK_WIDGET(this->get()));
    }
    virtual void set_size_request(int width, int height){
        gtk_widget_set_size_request(GTK_WIDGET(this->get()), width, height);
    }
    virtual void get_size_request(int *width, int *height){
        gtk_widget_get_size_request(GTK_WIDGET(this->get()), width, height);
    }
    virtual void set_opacity(gdouble opacity){
        gtk_widget_set_opacity(GTK_WIDGET(this->get()), opacity);
    }
    virtual double get_opacity(){
        return gtk_widget_get_opacity(GTK_WIDGET(this->get()));
    }
    virtual void set_overflow(GtkOverflow overflow){
        gtk_widget_set_overflow(GTK_WIDGET(this->get()), overflow);
    }
    virtual GtkOverflow get_overflow(){
        return gtk_widget_get_overflow(GTK_WIDGET(this->get()));
    }
    virtual IWidget get_ancestor(GType widget_type){
        return { gtk_widget_get_ancestor(GTK_WIDGET(this->get()), widget_type) };
    }
    virtual int get_scale_factor(){
        return gtk_widget_get_scale_factor(GTK_WIDGET(this->get()));
    }
    virtual GdkDisplay* get_display(){
        return gtk_widget_get_display(GTK_WIDGET(this->get()));
    }
    virtual GtkSettings* get_settings(){
        return gtk_widget_get_settings(GTK_WIDGET(this->get()));
    }
    virtual GdkClipboard* get_clipboard(){
        return gtk_widget_get_clipboard(GTK_WIDGET(this->get()));
    }
    virtual GdkClipboard* get_primary_clipboard(){
        return gtk_widget_get_primary_clipboard(GTK_WIDGET(this->get()));
    }
    virtual gboolean get_hexpand(){
        return gtk_widget_get_hexpand(GTK_WIDGET(this->get()));
    }
    virtual void set_hexpand(gboolean expand){
        gtk_widget_set_hexpand(GTK_WIDGET(this->get()), expand);
    }
    virtual gboolean get_hexpand_set(){
        return gtk_widget_get_hexpand_set(GTK_WIDGET(this->get()));
    }
    virtual void set_hexpand_set(gboolean set){
        gtk_widget_set_hexpand_set(GTK_WIDGET(this->get()), set);
    }
    virtual gboolean get_vexpand(){
        return gtk_widget_get_vexpand(GTK_WIDGET(this->get()));
    }
    virtual void set_vexpand(gboolean expand){
        gtk_widget_set_vexpand(GTK_WIDGET(this->get()), expand);
    }
    virtual gboolean get_vexpand_set(){
        return gtk_widget_get_vexpand_set(GTK_WIDGET(this->get()));
    }
    virtual void set_vexpand_set(gboolean set){
        gtk_widget_set_vexpand_set(GTK_WIDGET(this->get()), set);
    }
    virtual gboolean compute_expand(GtkOrientation orientation){
        return gtk_widget_compute_expand(GTK_WIDGET(this->get()), orientation);
    }
    virtual GtkAlign get_halign(){
        return gtk_widget_get_halign(GTK_WIDGET(this->get()));
    }
    virtual void set_halign(GtkAlign align){
        gtk_widget_set_halign(GTK_WIDGET(this->get()), align);
    }
    virtual GtkAlign get_valign(){
        return gtk_widget_get_valign(GTK_WIDGET(this->get()));
    }
    virtual void set_valign(GtkAlign align){
        gtk_widget_set_valign(GTK_WIDGET(this->get()), align);
    }
    virtual int get_margin_start(){
        return gtk_widget_get_margin_start(GTK_WIDGET(this->get()));
    }
    virtual void set_margin_start(int margin){
        gtk_widget_set_margin_start(GTK_WIDGET(this->get()), margin);
    }
    virtual int get_margin_end(){
        return gtk_widget_get_margin_end(GTK_WIDGET(this->get()));
    }
    virtual void set_margin_end(int margin){
        gtk_widget_set_margin_end(GTK_WIDGET(this->get()), margin);
    }
    virtual int get_margin_top(){
        return gtk_widget_get_margin_top(GTK_WIDGET(this->get()));
    }
    virtual void set_margin_top(int margin){
        gtk_widget_set_margin_top(GTK_WIDGET(this->get()), margin);
    }
    virtual int get_margin_bottom(){
        return gtk_widget_get_margin_bottom(GTK_WIDGET(this->get()));
    }
    virtual void set_margin_bottom(int margin){
        gtk_widget_set_margin_bottom(GTK_WIDGET(this->get()), margin);
    }
    virtual gboolean is_ancestor(GtkWidget *ancestor){
        return gtk_widget_is_ancestor(GTK_WIDGET(this->get()), ancestor);
    }
    virtual gboolean contains(double x, double y){
        return gtk_widget_contains(GTK_WIDGET(this->get()), x, y);
    }
    virtual IWidget widget_pick(double x, double y, GtkPickFlags flags){
        return { gtk_widget_pick(GTK_WIDGET(this->get()), x, y, flags) };
    }
    virtual void add_controller(GtkEventController *controller){
        gtk_widget_add_controller(GTK_WIDGET(this->get()), controller);
    }
    virtual void remove_controller(GtkEventController *controller){
        gtk_widget_remove_controller(GTK_WIDGET(this->get()), controller);
    }
    virtual PangoContext *create_pango_context(){
        return gtk_widget_create_pango_context(GTK_WIDGET(this->get()));
    }
    virtual PangoContext *get_pango_context(){
        return gtk_widget_get_pango_context(GTK_WIDGET(this->get()));
    }
    virtual void set_font_options(const cairo_font_options_t *options){
        gtk_widget_set_font_options(GTK_WIDGET(this->get()), options);
    }
    virtual const cairo_font_options_t *get_font_options(){
        return gtk_widget_get_font_options(GTK_WIDGET(this->get()));
    }
    virtual PangoLayout *create_pango_layout(const char *text){
        return gtk_widget_create_pango_layout(GTK_WIDGET(this->get()), text);
    }
    void set_direction(GtkTextDirection dir){
        gtk_widget_set_direction(GTK_WIDGET(this->get()), dir);
    }
    GtkTextDirection get_direction(){
        return gtk_widget_get_direction(GTK_WIDGET(this->get()));
    }
    virtual void set_default_direction(GtkTextDirection dir){
        gtk_widget_set_default_direction(dir);
    }
    virtual GtkTextDirection get_default_direction(){
        return gtk_widget_get_default_direction();
    }
    virtual void set_cursor(GdkCursor *cursor){
        gtk_widget_set_cursor(GTK_WIDGET(this->get()), cursor);
    }
    virtual void set_cursor_from_name(const char *name){
        gtk_widget_set_cursor_from_name(GTK_WIDGET(this->get()), name);
    }
    virtual GdkCursor *get_cursor(){
        return gtk_widget_get_cursor(GTK_WIDGET(this->get()));
    }
    virtual GList* list_mnemonic_labels(){
        return gtk_widget_list_mnemonic_labels(GTK_WIDGET(this->get()));
    }
    virtual void add_mnemonic_label(IWidget label){
        gtk_widget_add_mnemonic_label(GTK_WIDGET(this->get()), GTK_WIDGET(label.get()));
    }
    virtual void remove_mnemonic_label(IWidget label){
        gtk_widget_remove_mnemonic_label(GTK_WIDGET(this->get()), GTK_WIDGET(label.get()));
    }
    virtual void trigger_tooltip_query(){
        gtk_widget_trigger_tooltip_query(GTK_WIDGET(this->get()));
    }
    virtual void set_tooltip_text(const char *text){
        gtk_widget_set_tooltip_text(GTK_WIDGET(this->get()), text);
    }
    virtual const char *get_tooltip_text(){
        return gtk_widget_get_tooltip_text(GTK_WIDGET(this->get()));
    }
    virtual void set_tooltip_markup(const char *markup){
        gtk_widget_set_tooltip_markup(GTK_WIDGET(this->get()), markup);
    }
    virtual const char *get_tooltip_markup(){
        return gtk_widget_get_tooltip_markup(GTK_WIDGET(this->get()));
    }
    virtual void set_has_tooltip(gboolean has_tooltip){
        gtk_widget_set_has_tooltip(GTK_WIDGET(this->get()), has_tooltip);
    }
    virtual gboolean get_has_tooltip(){
        return gtk_widget_get_has_tooltip(GTK_WIDGET(this->get()));
    }
    virtual GType           requisition_get_type(){
        return gtk_requisition_get_type();
    }
    virtual GtkRequisition *requisition_new(){
        return gtk_requisition_new();
    }
    virtual GtkRequisition *requisition_copy(const GtkRequisition *requisition){
        return gtk_requisition_copy(requisition);
    }
    virtual void requisition_free(GtkRequisition       *requisition){
        gtk_requisition_free(requisition);
    }
    virtual gboolean in_destruction(){
        return gtk_widget_in_destruction(GTK_WIDGET(this->get()));
    }
    virtual void class_set_css_name (GtkWidgetClass *widget_class, const char *name){
        gtk_widget_class_set_css_name(widget_class, name);
    }
    virtual const char *class_get_css_name (GtkWidgetClass *widget_class){
        return gtk_widget_class_get_css_name(widget_class);
    }
    virtual guint add_tick_callback (GtkTickCallback  callback,
                                    gpointer         user_data,
                                    GDestroyNotify   notify){
        return gtk_widget_add_tick_callback(GTK_WIDGET(this->get()), callback, user_data, notify);
    }
    virtual void remove_tick_callback (guint            id){
        gtk_widget_remove_tick_callback(GTK_WIDGET(this->get()), id);
    }
    virtual void init_template(){
        gtk_widget_init_template(GTK_WIDGET(this->get()));
    }
    virtual GObject *get_template_child(GType widget_type, const char *name){
        return gtk_widget_get_template_child(GTK_WIDGET(this->get()), widget_type, name);
    }
    virtual void dispose_template(GType widget_type){
        gtk_widget_dispose_template(GTK_WIDGET(this->get()), widget_type);
    }
    virtual void class_set_template(GtkWidgetClass *widget_class, GBytes *template_bytes){
        gtk_widget_class_set_template(widget_class, template_bytes);
    }
    virtual void class_set_template_from_resource(GtkWidgetClass *widget_class, const char *resource_name){
        gtk_widget_class_set_template_from_resource(widget_class, resource_name);
    }
    virtual void class_bind_template_callback_full(GtkWidgetClass *widget_class, const char *callback_name, GCallback callback_symbol){
        gtk_widget_class_bind_template_callback_full(widget_class, callback_name, callback_symbol);
    }
    virtual void class_set_template_scope(GtkWidgetClass *widget_class, GtkBuilderScope *scope){
        gtk_widget_class_set_template_scope(widget_class, scope);
    }
    virtual void class_bind_template_child_full(GtkWidgetClass *widget_class, const char *name, gboolean internal_child, gssize struct_offset){
        gtk_widget_class_bind_template_child_full(widget_class, name, internal_child, struct_offset);
    }
    virtual void insert_action_group(const char *name, GActionGroup *group){
        gtk_widget_insert_action_group(GTK_WIDGET(this->get()), name, group);
    }
    virtual gboolean activate_action(const char *name, const char *format_string, ...){
        va_list args;
        va_start(args, format_string);
        gboolean ret = gtk_widget_activate_action(GTK_WIDGET(this->get()), name, format_string, args);
        va_end(args);
        return ret;
    }
    virtual gboolean activate_action_variant(const char *name, GVariant *args){
        return gtk_widget_activate_action_variant(GTK_WIDGET(this->get()), name, args);
    }
    virtual void activate_default(){
        gtk_widget_activate_default(GTK_WIDGET(this->get()));
    }
    virtual void set_font_map(PangoFontMap *font_map){
        gtk_widget_set_font_map(GTK_WIDGET(this->get()), font_map);
    }
    virtual PangoFontMap *get_font_map(){
        return gtk_widget_get_font_map(GTK_WIDGET(this->get()));
    }
    virtual IWidget get_first_child(){
        return { gtk_widget_get_first_child(GTK_WIDGET(this->get())) };
    }
    virtual IWidget get_last_child(){
        return { gtk_widget_get_last_child(GTK_WIDGET(this->get())) };
    }
    virtual IWidget get_next_sibling(){
        return { gtk_widget_get_next_sibling(GTK_WIDGET(this->get())) };
    }
    virtual IWidget get_prev_sibling(){
        return { gtk_widget_get_prev_sibling(GTK_WIDGET(this->get())) };
    }
    virtual GListModel *observe_children(){
        return gtk_widget_observe_children(GTK_WIDGET(this->get()));
    }
    virtual GListModel *observe_controllers(){
        return gtk_widget_observe_controllers(GTK_WIDGET(this->get()));
    }
    virtual void insert_after(IWidget parent, IWidget previous_sibling){
        gtk_widget_insert_after(GTK_WIDGET(this->get()), GTK_WIDGET(parent.get()), GTK_WIDGET(previous_sibling.get()));
    }
    virtual void insert_before(IWidget parent, IWidget next_sibling){
        gtk_widget_insert_before(GTK_WIDGET(this->get()), GTK_WIDGET(parent.get()), GTK_WIDGET(next_sibling.get()));
    }
    virtual void set_focus_child(IWidget child){
        gtk_widget_set_focus_child(GTK_WIDGET(this->get()), GTK_WIDGET(child.get()));
    }
    virtual IWidget get_focus_child(){
        return { gtk_widget_get_focus_child(GTK_WIDGET(this->get())) };
    }
    virtual void snapshot_child(IWidget child, GtkSnapshot *snapshot){
        gtk_widget_snapshot_child(GTK_WIDGET(this->get()), GTK_WIDGET(child.get()), snapshot);
    }
    virtual gboolean should_layout(){
        return gtk_widget_should_layout(GTK_WIDGET(this->get()));
    }
    virtual const char *get_css_name(){
        return gtk_widget_get_css_name(GTK_WIDGET(this->get()));
    }
    virtual void add_css_class(const char *css_class){
        gtk_widget_add_css_class(GTK_WIDGET(this->get()), css_class);
    }
    virtual void remove_css_class(const char *css_class){
        gtk_widget_remove_css_class(GTK_WIDGET(this->get()), css_class);
    }
    virtual gboolean has_css_class(const char *css_class){
        return gtk_widget_has_css_class(GTK_WIDGET(this->get()), css_class);
    }
    virtual char **get_css_classes(){
        return gtk_widget_get_css_classes(GTK_WIDGET(this->get()));
    }
    virtual void set_css_classes(const char **classes){
        gtk_widget_set_css_classes(GTK_WIDGET(this->get()), classes);
    }
    virtual void get_color(GdkRGBA *color){
        gtk_widget_get_color(GTK_WIDGET(this->get()), color);
    }
    virtual void class_install_action(GtkWidgetClass *widget_class, const char *action_name, const char *parameter_type, GtkWidgetActionActivateFunc activate){
        gtk_widget_class_install_action(widget_class, action_name, parameter_type, activate);
    }
    virtual void class_install_property_action(GtkWidgetClass *widget_class, const char *action_name, const char *property_name){
        gtk_widget_class_install_property_action(widget_class, action_name, property_name);
    }
    virtual gboolean class_query_action(GtkWidgetClass *widget_class, guint index_, GType *owner, const char **action_name, const GVariantType **parameter_type, const char **property_name){
        return gtk_widget_class_query_action(widget_class, index_, owner, action_name, parameter_type, property_name);
    }
    virtual void action_set_enabled(GtkWidget *widget, const char *action_name, gboolean enabled){
        gtk_widget_action_set_enabled(widget, action_name, enabled);
    }
    virtual void class_set_accessible_role(GtkWidgetClass *widget_class, GtkAccessibleRole accessible_role){
        gtk_widget_class_set_accessible_role(widget_class, accessible_role);
    }
    virtual GtkAccessibleRole class_get_accessible_role(GtkWidgetClass *widget_class){
        return gtk_widget_class_get_accessible_role(widget_class);
    }
};


#define INHERIT_FROM_IWIDGET(CLASSNAME)\
public: \
    virtual ~CLASSNAME() = default; \
    CLASSNAME() = default; \
    CLASSNAME(std::string widgetName): IWidget(widgetName){} \
    CLASSNAME(GtkWidget* widget, std::string widgetName = ""): IWidget(widget, widgetName){}\
    CLASSNAME(gtkaa::sptrGTKWidget widget, std::string widgetName = ""): IWidget(widget, widgetName){}\
    CLASSNAME(IWidget& widget): IWidget(widget){}\
    CLASSNAME(const IWidget& widget): IWidget(widget){}
}
#endif