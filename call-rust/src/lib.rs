extern crate libc;

use std::ffi::CStr;
use libc::{int32_t, c_char, ssize_t};


#[no_mangle]
pub extern "C" fn mult2(x: int32_t) -> int32_t {
    2 * x
}


#[no_mangle]
pub extern "C" fn find_substr(haystack: *const c_char, needle: *const c_char) -> ssize_t {
    let haystack = unsafe { CStr::from_ptr(haystack).to_str() };
    let needle = unsafe { CStr::from_ptr(needle).to_str() };
    match (haystack, needle) {
        (Ok(h), Ok(n)) => {
            match h.find(n) {
                Some(p) => p as ssize_t,
                None => -1,
            }
        }
        _ => -1,
    }
}


#[repr(C)]
pub struct DivMod {
    pub div: int32_t,
    pub mod_: int32_t,
}

#[no_mangle]
pub extern "C" fn divmod_impl(x: int32_t, y: int32_t, divmod: *mut DivMod) {
    let (div, mod_) = match y {
        0 => (0, 0),
        _ => (x / y, x % y),
    };

    unsafe {
        (*divmod).div = div;
        (*divmod).mod_ = mod_;
    }
}
