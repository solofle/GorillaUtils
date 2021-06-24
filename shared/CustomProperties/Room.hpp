#pragma once

#include "beatsaber-hook/shared/utils/il2cpp-functions.hpp"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"

#include <type_traits>
#include <optional>
#include "Photon/Realtime/Room.hpp"
#include "Photon/Realtime/WebFlags.hpp"
#include "ExitGames/Client/Photon/Hashtable.hpp"

namespace GorillaUtils::Room
{
    using Room = Photon::Realtime::Room;
    using WebFlags = Photon::Realtime::WebFlags;
    using Hashtable = ExitGames::Client::Photon::Hashtable;
    using Hashtable_Base = System::Collections::Generic::Dictionary_2<Il2CppObject*, Il2CppObject*>;

    /// @brief gets a property from the room custom properties
    /// @param room the room to get the property on
    /// @param property the name of the property
    /// @return optional template value, nullopt for no room, no properties or value nonexistent
    template <typename T>
    std::optional<T> GetProperty(Room* room, std::string property)
    {
        if (!room) return std::nullopt;
        Hashtable* properties = room->get_CustomProperties();
        if (!properties) return std::nullopt;

        Il2CppString* propCS = il2cpp_utils::newcsstr(property);
        if (!properties->Hashtable_Base::ContainsKey(propCS)) return std::nullopt;

        Il2CppObject* item = properties->get_Item(propCS);
        if (std::is_pointer<T>::value) return (T)item;
        else return *(T*)il2cpp_functions::object_unbox(item);
    }

    /// @brief sets a property on the room
    /// @param room the room to set on
    /// @param property the name of the property
    /// @param val the value to set
    template <typename T> 
    void SetProperty(Room* room, std::string property, T val)
    {
        if (!room) return;
        Il2CppString* propCS = il2cpp_utils::newcsstr(property);
        Il2CppObject* key = il2cpp_functions::value_box(classof(Il2CppString*), propCS);
        Il2CppObject* value = il2cpp_functions::value_box(classof(T), std::is_pointer<T>::value ? val : &val);
        
        Hashtable* properties = *il2cpp_utils::New<Hashtable*>();
        properties->Hashtable_Base::Add(key, value);

        room->SetCustomProperties(properties, nullptr, WebFlags::_get_Default());
    }
}