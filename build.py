from cpt.packager import ConanMultiPackager

if __name__ == "__main__":
    builder = ConanMultiPackager(archs=["x86_64"], build_policy="missing", upload_dependencies=True)
    builder.add_common_builds()
    builder.run()
