#ifndef APPLICATIONCLIENTCORE_GLOBAL_H
#define APPLICATIONCLIENTCORE_GLOBAL_H

#if defined(APPLICATIONCLIENTCORE_LIBRARY)
#define APPLICATIONCLIENTCORE_EXPORT Q_DECL_EXPORT
#else
#define APPLICATIONCLIENTCORE_EXPORT Q_DECL_IMPORT
#endif

#ifdef APPLICATIONCLIENTCORE_LIBRARY
#define REGISTER_HPP_APPLICATIONCLIENTCORE_LIBRARY QX_REGISTER_HPP_EXPORT_DLL
#define REGISTER_CPP_APPLICATIONCLIENTCORE_LIBRARY QX_REGISTER_CPP_EXPORT_DLL
#else // _BUILDING_HERP_AUTHORIZATION_MODULE
#define REGISTER_HPP_APPLICATIONCLIENTCORE_LIBRARY QX_REGISTER_HPP_IMPORT_DLL
#define REGISTER_CPP_APPLICATIONCLIENTCORE_LIBRARY QX_REGISTER_CPP_IMPORT_DLL
#endif // _BUILDING_HERP_AUTHORIZATION_MODULE

#endif // APPLICATIONCLIENTCORE_GLOBAL_H
