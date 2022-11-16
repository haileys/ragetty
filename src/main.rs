use std::ffi::CString;
use std::os::unix::ffi::OsStringExt;

mod ffi;

fn main() {
    let mut args = std::env::args_os()
        .map(|arg| CString::new(arg.into_vec()).unwrap().into_raw())
        .collect::<Vec<_>>();

    let argc = i32::try_from(args.len()).unwrap();
    let argv = args.as_mut_ptr();
    let rc = unsafe { ffi::c_main(argc, argv) };

    std::process::exit(rc);
}
