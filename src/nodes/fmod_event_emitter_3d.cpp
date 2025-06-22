#include <nodes/fmod_event_emitter_3d.h>

using namespace godot;

void FmodEventEmitter3D::update_in_valid_viewport_impl(const Ref<FmodEvent>& p_event) const {
    bool shares_space = false;
    for (int i = 0; i < FmodServer::get_singleton()->get_valid_viewports_number(); ++i) {
        if (FmodServer::get_singleton()->get_valid_viewport(i) == get_viewport()) {
            shares_space = true;
            break;
        }
    }
    if (shares_space) {
        p_event->set_volume(get_volume());
    } else {
        p_event->set_volume(0.0);
    }
}

void FmodEventEmitter3D::set_space_attribute_impl(const Ref<FmodEvent>& p_event) const {
    p_event->set_3d_attributes(get_global_transform());
}

void FmodEventEmitter3D::_ready() {
    FmodEventEmitter<FmodEventEmitter3D, Node3D>::_ready();
}

void FmodEventEmitter3D::_process(double delta) {
    FmodEventEmitter<FmodEventEmitter3D, Node3D>::_process(delta);
}

void FmodEventEmitter3D::_notification(int p_what) {
    FmodEventEmitter<FmodEventEmitter3D, Node3D>::_notification(p_what);
}

void FmodEventEmitter3D::_exit_tree() {
    FmodEventEmitter<FmodEventEmitter3D, Node3D>::_exit_tree();
}

void FmodEventEmitter3D::_bind_methods() {
    FmodEventEmitter<FmodEventEmitter3D, Node3D>::_bind_methods();
}

void FmodEventEmitter3D::free_impl() {
    queue_free();
}
