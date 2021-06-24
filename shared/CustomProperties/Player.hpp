#pragma once

#include "beatsaber-hook/shared/utils/il2cpp-functions.hpp"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"

#include <optional>
#include <type_traits>
#include "Photon/Realtime/Player.hpp"
#include "Photon/Realtime/WebFlags.hpp"
#include "ExitGames/Client/Photon/Hashtable.hpp"

namespace GorillaUtils::Player
{
    using Player = Photon::Realtime::Player;
    using WebFlags = Photon::Realtime::WebFlags;
    using Hashtable = ExitGames::Client::Photon::Hashtable;
    using Hashtable_Base = System::Collections::Generic::Dictionary_2<Il2CppObject*, Il2CppObject*>;

    /// @brief gets a property from the player custom properties
    /// @param player the player to get the property on
    /// @param property the name of the property
    /// @return optional template value, nullopt for no player, no properties or value nonexistent
    template <typename T> 
    std::optional<T> GetProperty(Player* player, std::string property)
    {
        if (!player) return std::nullopt;
        Hashtable* properties = player->get_CustomProperties();
        if (!properties) return std::nullopt;

        Il2CppString* propCS = il2cpp_utils::newcsstr(property);
        if (!properties->Hashtable_Base::ContainsKey(propCS)) return std::nullopt;

        Il2CppObject* item = properties->get_Item(propCS);
        if (std::is_pointer<T>::value) return (T)item;
        else return *(T*)il2cpp_functions::object_unbox(item);
    }

    /// @brief sets a property on the player
    /// @param player the player to set on
    /// @param property the name of the property
    /// @param val the value to set
    template <typename T> 
    void SetProperty(Player* player, std::string property, T val)
    {
        if (!player) return;
        Il2CppString* propCS = il2cpp_utils::newcsstr(property);
        Il2CppObject* key = il2cpp_functions::value_box(classof(Il2CppString*), propCS);
        Il2CppObject* value;

        if constexpr (std::is_pointer_v<T>) value = val;
        else value = il2cpp_functions::value_box(classof(T), &val);
        
        Hashtable* properties = *il2cpp_utils::New<Hashtable*>();
        properties->Hashtable_Base::Add(key, value);

        player->SetCustomProperties(properties, nullptr, WebFlags::_get_Default());
    }
}