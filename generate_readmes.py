import os

def generate_folder_tree(dir_path, prefix=""):
    tree_lines = []
    items = sorted(os.listdir(dir_path))
    for i, item in enumerate(items):
        if item.startswith('.') or item == 'README.md':
            continue
        item_path = os.path.join(dir_path, item)
        branch = "├── " if i < len(items) - 1 else "└── "
        if os.path.isdir(item_path):
            tree_lines.append(f"{prefix}{branch}📁 {item}")
            sub_prefix = prefix + ("│   " if i < len(items) - 1 else "    ")
            tree_lines.extend(generate_folder_tree(item_path, sub_prefix))
        else:
            tree_lines.append(f"{prefix}{branch}📄 {item}")
    return tree_lines

def generate_readme(semester_dir):
    tree = generate_folder_tree(semester_dir)
    semester_name = os.path.basename(semester_dir)
    readme_content = f"# 📘 {semester_name} Contents\n\n[⬅ Back to Main README](../README.md)\n\n```\n📁 {semester_name}\n" + "\n".join(tree) + "\n```"
    
    with open(os.path.join(semester_dir, "README.md"), "w", encoding="utf-8") as f:
        f.write(readme_content)

def update_main_readme(base_path, semester_names):
    readme_path = os.path.join(base_path, "README.md")
    if not os.path.exists(readme_path):
        return
    with open(readme_path, "r", encoding="utf-8") as f:
        content = f.read()

    start_marker = "<!-- SEMESTER-LIST-START -->"
    end_marker = "<!-- SEMESTER-LIST-END -->"

    new_list = "\n".join([f"- [{name}](./{name}/README.md)" for name in semester_names])
    new_section = f"{start_marker}\n{new_list}\n{end_marker}"

    if start_marker in content and end_marker in content:
        pre = content.split(start_marker)[0]
        post = content.split(end_marker)[1]
        new_content = pre + new_section + post
    else:
        new_content = content + "\n\n" + new_section

    with open(readme_path, "w", encoding="utf-8") as f:
        f.write(new_content)

if __name__ == "__main__":
    base_path = os.getcwd()
    semesters = []

    for name in sorted(os.listdir(base_path)):
        if name.lower().startswith("semester") and os.path.isdir(name):
            semesters.append(name)
            generate_readme(os.path.join(base_path, name))

    update_main_readme(base_path, semesters)
