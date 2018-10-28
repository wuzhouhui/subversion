from svntest.main import SVN_PROP_MERGEINFO, is_os_windows
def make_patch_path(sbox, name='my.patch'):
  dir = sbox.add_wc_path('patches')
  os.mkdir(dir)
  return os.path.abspath(os.path.join(dir, name))

  patch_file_path = make_patch_path(sbox)
  expected_output = [
    'U         %s\n' % sbox.ospath('A/D/gamma'),
    'U         %s\n' % sbox.ospath('iota'),
    'A         %s\n' % sbox.ospath('new'),
    'U         %s\n' % sbox.ospath('A/mu'),
    'D         %s\n' % sbox.ospath('A/B/E/beta'),
  ]
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
                                       None, # expected err
                                       1, # check-props
                                       1) # dry-run
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch('', os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch('', os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
                                       os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  expected_status.add({'A/D/H/chi' : Item(status='! ', wc_rev=1)})
  expected_status.add({'A/D/H/omega' : Item(status='D ', wc_rev=1)})
  expected_status.add({'A/D/H/psi' : Item(status='D ', wc_rev=1)})
  expected_status.add({'A/B' : Item(status='D ', wc_rev=1)})
  expected_status.add({'A/B/E' : Item(status='D ', wc_rev=1)})
  expected_status.add({'A/B/E/beta' : Item(status='D ', wc_rev=1)})
  expected_status.add({'A/B/E/alpha' : Item(status='D ', wc_rev=1)})
  expected_status.add({'A/B/lambda' : Item(status='D ', wc_rev=1)})
  expected_status.add({'A/B/F' : Item(status='D ', wc_rev=1)})
                                       os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
      expected_output = [
        'G         %s\n' % sbox.ospath('A/mu'),
      ]
      svntest.actions.run_and_verify_patch(wc_dir,
                                           os.path.abspath(patch_file_path),
                                           expected_output,
                                           expected_disk,
                                           expected_status,
                                           expected_skip,
                                           None, # expected err
                                           1, # check-props
                                           1) # dry-run
      svntest.actions.run_and_verify_svn(expected_output, [], 'revert', '-R', wc_dir)
  patch_file_path = make_patch_path(sbox)
      svntest.actions.run_and_verify_patch(wc_dir,
                                           os.path.abspath(patch_file_path),
                                           expected_output,
                                           expected_disk,
                                           expected_status,
                                           expected_skip,
                                           None, # expected err
                                           1, # check-props
                                           1) # dry-run
  patch_file_path = make_patch_path(sbox)
      expected_output = [
        'G         %s\n' % sbox.ospath('A/mu'),
      ]
      svntest.actions.run_and_verify_patch(wc_dir,
                                           os.path.abspath(patch_file_path),
                                           expected_output,
                                           expected_disk,
                                           expected_status,
                                           expected_skip,
                                           None, # expected err
                                           1, # check-props
                                           1) # dry-run
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.main.file_write(patch_file_path, ''.join(unidiff_patch))
  expected_skip = wc.State('', { })
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
                                       None, # expected err
                                       1, # check-props
                                       1) # dry-run
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
    # with no trailing context. Currently, Subversion applies this patch
    # multiple times, which matches the behaviour of Larry Wall's patch
    # implementation. A more complicated hunk matching algorithm is needed
    # to detect the duplicate application in this case. GNU patch does detect
    # the duplicate application. Should Subversion be taught to detect it,
    # we need this line here:
    # '>         hunk @@ -1,1 +1,2 @@ already applied\n',
    'Skipped \'%s\'\n' % beta_path,
  ] + svntest.main.summary_of_conflicts(skipped_paths=1)

  expected_skip = wc.State('', {beta_path : Item(verb='Skipped')})

  # See above comment about the iota patch being applied twice.
  iota_contents += "Some more bytes\n"
  expected_disk.tweak('iota', contents=iota_contents)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch('', os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
    "new file mode 10644\n",
    "deleted file mode 10644\n",
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  expected_output = [
    'U         %s\n' % sbox.ospath('A/D/gamma'),
    'U         %s\n' % sbox.ospath('iota'),
    'A         %s\n' % sbox.ospath('new'),
    'U         %s\n' % sbox.ospath('A/mu'),
    'D         %s\n' % sbox.ospath('A/B/E/beta'),
  ]
  expected_skip = wc.State('', { })
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
                                       None, # expected err
                                       1, # check-props
                                       1) # dry-run
  expected_output = [
    'G         %s\n' % sbox.ospath('A/D/gamma'),
    'G         %s\n' % sbox.ospath('iota'),
    'D         %s\n' % sbox.ospath('new'),
    'G         %s\n' % sbox.ospath('A/mu'),
    'A         %s\n' % sbox.ospath('A/B/E/beta'),
  ]
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
                                       None, # expected err
                                       1, # check-props
                                       1, # dry-run
  patch_file_path = make_patch_path(sbox)
    unidiff_patch += ['\ No newline at end of property']
  svntest.main.file_write(patch_file_path, ''.join(unidiff_patch))
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  if is_os_windows():
    # On Windows 'svn pg' uses \r\n as EOL.
    value = value.replace('\n', '\r\n')

  svntest.actions.check_prop('k', wc_dir, [value])
@SkipUnless(svntest.main.is_posix_os)
  patch_file_path = make_patch_path(sbox)
  expected_output = [
    'A         %s\n' % sbox.ospath('iota_symlink'),
  ]
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
                                       None, # expected err
                                       1, # check-props
                                       1) # dry-run
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  expected_disk.tweak('iota', contents=iota_contents + "Some more bytes")
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
                                       0) # dry-run
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch('', os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  patch_file_path = make_patch_path(sbox)
  expected_output = [
    'D         %s\n' % sbox.ospath('A/D/G/pi'),
    'D         %s\n' % sbox.ospath('A/D/G/rho'),
    'D         %s\n' % sbox.ospath('A/D/G/tau'),
    'D         %s\n' % sbox.ospath('A/D/G'),
    'D         %s\n' % sbox.ospath('A/D/H/chi'),
    'D         %s\n' % sbox.ospath('A/D/H/omega'),
    'D         %s\n' % sbox.ospath('A/D/H/psi'),
    'D         %s\n' % sbox.ospath('A/D/H'),
    'D         %s\n' % sbox.ospath('A/D/gamma'),
    'D         %s\n' % sbox.ospath('A/D'),
    'D         %s\n' % sbox.ospath('iota'),
    'A         %s\n' % sbox.ospath('A/D'),
    'A         %s\n' % sbox.ospath('iota'),
  ]
  svntest.actions.run_and_verify_svn(expected_output, [],
                                     'patch', patch_file_path, sbox.wc_dir)
  patch_file_path = make_patch_path(sbox)
  expected_output = [
    'C         %s\n' % sbox.ospath('test'),
    '>         rejected hunk @@ -1,1 +1,1 @@\n',
  ] + svntest.main.summary_of_conflicts(text_conflicts=1)
  svntest.actions.run_and_verify_svn(expected_output, [],
                                     'patch', patch_file_path, wc_dir)
  patch_file_path = make_patch_path(sbox)
    "\n"
  svntest.actions.run_and_verify_svn(expected_output, [],
                                     'patch', patch_file_path, wc_dir)

    'lf.txt'            : Item(contents="\n"),
  svntest.actions.verify_disk(wc_dir, expected_disk)
  svntest.main.file_write(sbox.ospath('test.txt'), '\n'.join([
    ]))
  svntest.main.file_write(sbox.ospath('test_v2.txt'), '\n'.join([
    ]))
  patch_path = sbox.ospath('patch.diff')
  svntest.main.file_write(patch_path, ''.join(out_text))
  expected_output = [
    'G         %s\n' % sbox.ospath('test.txt'),
  ]
  # Current result: lf.txt patched ok, new created, empty succeeds with offset.
  svntest.actions.run_and_verify_svn(expected_output, [],
                                     'patch', patch_path, wc_dir)
  if not filecmp.cmp(sbox.ospath('test.txt'), sbox.ospath('test_v2.txt')):
    raise svntest.Failure("Patch result not identical")
@XFail()
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  expected_output = [ 'G         %s\n' % sbox.ospath('iota') ]
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  expected_output = [ 'A         %s\n' % sbox.ospath('iota2'),
                      'D         %s\n' % sbox.ospath('iota')]
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
                                       expected_status, expected_skip)
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  # Second application skips
    'Skipped \'%s\'\n' % sbox.ospath('A/B/E/beta'),
  ] + svntest.main.summary_of_conflicts(skipped_paths=1)
  expected_skip = wc.State('', {
    sbox.ospath('A/B/E/beta') :  Item(verb='Skipped'),
  })
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
    "+++ A/B/E/beta\n",
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  patch_file_path = make_patch_path(sbox)
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),
  svntest.actions.run_and_verify_patch(wc_dir, os.path.abspath(patch_file_path),