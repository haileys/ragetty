fn main() {
    let out_path = std::path::PathBuf::from(std::env::var("OUT_DIR").unwrap());

    println!("cargo:rerun-if-changed=agetty.h");

    cc::Build::new()
        .file("src/agetty.c")
        .include("src")
        .compile("agetty");

    bindgen::Builder::default()
        .header("src/agetty.h")
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .generate()
        .unwrap()
        .write_to_file(out_path.join("bindings.rs"))
        .unwrap();
}
