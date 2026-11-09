# Lab 2 — Linux Navigation and File Management: individual report

Copy this template to `lab2/README.md` in your own course repository. Follow [the instructions](lab2-instruction.md). Your prediction, debrief and checkpoint answers are already saved by `oslab`; do not copy them here. The marks come from those records and your evidence files; this report is your own record of the lab.

- Student name/ID: Ousaphea Sun / e20230369
- Ubuntu username: gic-sun-ousaphea
- My values (`oslab values lab2`): file1 = `travel claims.txt`, file2 = `payroll may.txt`, owner = Sales, reader = Engineering, third = Marketing
- Files: `evidence/paths.txt`, `evidence/tree.txt`, `evidence/checkpoint.txt`

## What I Did

| Step | My command | Current folder when I ran it |
|---|---|---|
| Move the first file (relative destination) | `mv -- "$file1" ../reports/` | `~/oslab-work/lab2/incoming/` |
| Move the second file (absolute paths) | `mv -- "$OSLAB_WORKSPACE/lab2/incoming/$file2" "$OSLAB_WORKSPACE/lab2/reports/"` | `~/oslab-work/lab2/` |
| Read the report from my reader department (relative path) | `cat "../$owner/$file1"` | `~/oslab-work/lab2/TechCorp/Engineering/` |
| The path error I made on purpose, and its message | `cat "reports/$file1"` — `cat: 'reports/travel claims.txt': No such file or directory` | `~/oslab-work/lab2/TechCorp/Engineering/` |
| The relative path that fixed it | `../../reports/travel claims.txt` | `~/oslab-work/lab2/TechCorp/Engineering/` |

## Explanation

A correct file name can still give "No such file or directory" because a relative path starts from the current working directory. If I am inside the Engineering folder, the path `reports/travel claims.txt` does not work because the reports folder is not inside Engineering. I must use the correct relative path, `../../reports/travel claims.txt`, to go back to the lab folder and access the report. The `mv` command moves a file from one location to another, while `cp` creates a copy and keeps the original file. In this lab, I moved both reports into `reports/` and copied them into the Sales department while keeping the original reports.

## What My Tests Do Not Prove

The `ls` command shows the file names and their locations, but it does not prove that the contents are identical. The `cmp` command compares the files byte by byte, but it does not prove that the original contents are correct or meaningful.

## Plus / Challenge (only if you did them)

Not recorded.

## AI Note (optional)

An AI suggestion was to use `../../reports/travel claims.txt` to access the report from the Engineering department. I tested this path using the `cat` command and confirmed that it successfully displayed the report.
