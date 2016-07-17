require 'minitest/autorun'

class MytailTest < Minitest::Test

  def test_argument_is_not_a_number
    expected = "error: not a valid format. Use ./mytail -n <nr>\n"
    assert_equal expected, `./mytail fg`
  end

  def test_argument_greater_than_max_allowed
    expected = "error: can't print more than 20 lines\n"
    assert_equal expected, `./mytail -n 99999999999999999999`
  end

  def test_input_line_is_too_long
    input_file = "test_data/large_line.txt"

    expected = "error: input line is too long.\n"
    assert_equal expected, `./mytail < #{input_file}`
  end

  def test_out_of_memory
    input_file = "test_data/large.txt"

    output = `./mytail -n 2 < #{input_file}`
    assert_equal "error: out of memory.\n", output
  end

  def test_run_with_no_errors
    input_file = "test_data/four_lines.txt"

    output = `./mytail -n 4 < #{input_file}`
    assert_equal "zz\ndd\nrr\nvv\n", output
  end

end
